#pragma once

#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
#include <memory>


class VideoArray
{

public:

	VideoArray(size_t number_of_videos, std::string file_type) : m_number_of_videos{ number_of_videos }, m_file_type{file_type}
	{
		for (size_t i{}; i < m_number_of_videos; ++i)
		{
			std::string video_name = std::to_string(i) + m_file_type;
			m_video_array.push_back(std::make_shared<cv::VideoCapture>(video_name));
		}

		for (const auto& video : m_video_array)
		{
			m_frame_counts.push_back(video->get(cv::CAP_PROP_FRAME_COUNT));
			m_frame_rates.push_back(video->get(cv::CAP_PROP_FPS));
		}

		for (size_t i{}; i < m_number_of_videos; ++i)
			m_durations.push_back(m_frame_counts.at(i) / m_frame_rates.at(i));

		for (const auto& frame_count : m_frame_counts)
			std::cout << frame_count << "\n";
		std::cout << "frame_counts size():\t" << m_frame_counts.size() << std::endl;
	}

	std::shared_ptr<cv::VideoCapture> get_video(size_t element) { return m_video_array.at(element); }
	size_t get_number_of_videos() { return m_number_of_videos; }
	std::string get_file_type() { return m_file_type; }
	std::vector<double> get_durations_vector() const { return m_durations; }
	double get_duration(size_t element) const { return m_durations.at(element); }
	std::vector<size_t> get_frame_counts() const{ return m_frame_counts; }
	size_t get_frame_count(size_t element) const { return m_frame_counts.at(element); }

private:

	size_t m_number_of_videos;
	std::string m_file_type;
	std::vector<std::shared_ptr<cv::VideoCapture>> m_video_array;
	std::vector<size_t> m_frame_counts;
	std::vector<double> m_frame_rates;
	std::vector<double> m_durations;

};

