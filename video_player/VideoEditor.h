#pragma once

#include "VideoPlayer.h"


class VideoEditor
{



public:

	VideoEditor(size_t number_of_videos, std::string file_type) : m_number_of_videos{ number_of_videos }, m_video_player{ m_number_of_videos, file_type }
	{
	}


	void set_min_frames(size_t min) { min_frames = min; }
	void set_max_frames(size_t max) { max_frames = max; }

	std::vector<std::vector<cv::Mat>> total_random_editing(size_t lenght_in_frames, size_t number_of_cuts);
	std::vector<cv::Mat> total_random_editing_one_dimensional(size_t lenght_in_frames, size_t number_of_cuts);
	std::vector<std::vector<cv::Mat>> total_random_editing(size_t number_of_cuts);
	std::vector<std::vector<cv::Mat>> total_random_editing_variable_lenght(size_t number_of_cuts, size_t max_lenght_of_cuts);
private:

	size_t m_number_of_videos;
	VideoPlayer m_video_player;
	size_t min_frames;
	size_t max_frames;
	RandomNumber m_random_generator;
};

