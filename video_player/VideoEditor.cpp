#include "VideoEditor.h"


std::vector<std::vector<cv::Mat>> VideoEditor::total_random_editing(size_t lenght_in_frames, size_t number_of_cuts)
{

	std::vector<std::vector<cv::Mat>> two_dimensional_vector;
	size_t remaining_lenght{ lenght_in_frames };

	for (size_t i{}; i < number_of_cuts; ++i)
	{
		size_t video_to_use{ m_random_generator.get_random_size_t(0, m_number_of_videos - 1)};
		size_t lenght_of_cut{ m_random_generator.get_random_size_t(1, remaining_lenght) };
		size_t starting_frame{ m_random_generator.get_random_size_t(0, (m_video_player.get_video_array().get_frame_count(video_to_use) - lenght_of_cut)) };
		remaining_lenght -= lenght_of_cut;
		std::cout << std::format("\nvideo_to_use:{}\nlenght_of_cut:\t{}\nstarting_frame:\t{}\nremaining_lenght:\{}\n", video_to_use, lenght_of_cut, starting_frame, remaining_lenght);
		if (remaining_lenght <= 0)
			break;

		std::vector<cv::Mat> frames{ m_video_player.get_specific_part_of_video(video_to_use, starting_frame, lenght_of_cut) };
		two_dimensional_vector.push_back(frames);
	}
	return two_dimensional_vector;
}

std::vector<cv::Mat> VideoEditor::total_random_editing_one_dimensional(size_t lenght_in_frames, size_t number_of_cuts)
{	
	std::vector<cv::Mat> frame_vector;
	size_t remaining_lenght{ lenght_in_frames };

	for (size_t i{}; i < number_of_cuts; ++i)
	{
		size_t video_to_use{ m_random_generator.get_random_size_t(0, m_number_of_videos - 1) };
		size_t lenght_of_cut{ m_random_generator.get_random_size_t(1, remaining_lenght) };
		size_t starting_frame{ m_random_generator.get_random_size_t(0, (m_video_player.get_video_array().get_frame_counts().at(video_to_use) - lenght_of_cut)) };
		remaining_lenght -= lenght_of_cut;
		std::cout << std::format("\nvideo_to_use:{}\nlenght_of_cut:\t{}\nstarting_frame:\t{}\nremaining_lenght:\{}\n", video_to_use, lenght_of_cut, starting_frame, remaining_lenght);
		if (remaining_lenght <= 0)
			break;

		std::vector<cv::Mat> frames{ m_video_player.get_specific_part_of_video(video_to_use, starting_frame, lenght_of_cut) };

	}
	return frame_vector;
}

std::vector<std::vector<cv::Mat>> VideoEditor::total_random_editing(size_t number_of_cuts)
{

	std::vector<std::vector<cv::Mat>> two_dimensional_vector;

	for (size_t i{}; i < number_of_cuts; ++i)
	{
		size_t video_to_use{ m_random_generator.get_random_size_t(0, m_number_of_videos - 1) };
		size_t lenght_of_cut{ m_random_generator.get_random_size_t(1, m_video_player.get_video_array().get_frame_count(video_to_use)) };
		size_t starting_frame{ m_random_generator.get_random_size_t(0, (m_video_player.get_video_array().get_frame_count(video_to_use) - lenght_of_cut)) };
		std::cout << std::format("\nvideo_to_use:{}\nlenght_of_cut:\t{}\nstarting_frame:\t{}\n", video_to_use, lenght_of_cut, starting_frame);


		std::vector<cv::Mat> frames{ m_video_player.get_specific_part_of_video(video_to_use, starting_frame, lenght_of_cut) };
		two_dimensional_vector.push_back(frames);
	}
	return two_dimensional_vector;
}

std::vector<std::vector<cv::Mat>> VideoEditor::total_random_editing_variable_lenght(size_t number_of_cuts, size_t max_lenght_of_cuts)
{

	std::vector<std::vector<cv::Mat>> two_dimensional_vector;
	std::vector<cv::Mat> frames;
	for (size_t i{}; i < number_of_cuts; ++i)
	{
		size_t video_to_use{ m_random_generator.get_random_size_t(0, m_number_of_videos - 1) };
		size_t max_possible_length = std::min(max_lenght_of_cuts, m_video_player.get_video_array().get_frame_count(video_to_use));
		size_t lenght_of_cut{ m_random_generator.get_random_size_t(1, max_possible_length) };
		size_t starting_frame{ m_random_generator.get_random_size_t(0, (m_video_player.get_video_array().get_frame_count(video_to_use) - lenght_of_cut)) };
		std::cout << std::format("\nnumber_of_cut:\t{}\nvideo_to_use:{}\nlenght_of_cut:\t{}\nstarting_frame:\t{}\n", i, video_to_use, lenght_of_cut, starting_frame);


		frames = m_video_player.get_specific_part_of_video(video_to_use, starting_frame, lenght_of_cut);
		two_dimensional_vector.push_back(frames);
		frames.clear();
	}
	return two_dimensional_vector;
}

 