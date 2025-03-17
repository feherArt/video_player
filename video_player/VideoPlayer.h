#pragma once

#include "VideoArray.h"
#include "RandomNumber.h"
#include <stdexcept>
#include <format>


class VideoPlayer
{

public:

	VideoPlayer(size_t number_of_videos, std::string file_type) : m_video_array{ number_of_videos, file_type }
	{
		//cv::namedWindow("window", cv::WINDOW_KEEPRATIO);
	}

	void play_random_videos(size_t number_of_frames_to_write);
	void display_random_video();
	cv::Mat get_image();
	cv::Mat get_random_image(size_t random_min, size_t random_max);
	std::vector<cv::Mat> get_specific_part_of_video(size_t video_to_use, size_t starting_frame, size_t number_of_frames_to_use);
	const VideoArray& get_video_array() const { return m_video_array; }

private:

	VideoArray m_video_array;
	/*cv::Size m_full_hd{1920, 1080};
	int m_fourcc{ cv::VideoWriter::fourcc('H', '2', '6', '4') };
	double m_video_witer_frame_rate{ 60.0f };
	std::string m_output_file_name{ "output.mp4" };
	cv::VideoWriter m_video_writer{m_output_file_name, m_fourcc, m_video_witer_frame_rate, m_full_hd};
	*/
	RandomNumber m_random_generator;

};

