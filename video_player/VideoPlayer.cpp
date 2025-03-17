#include "VideoPlayer.h"

void VideoPlayer::play_random_videos(size_t number_of_frames_to_write)
{
	
	for (size_t i{}; i < number_of_frames_to_write; ++i)
	{
		cv::Mat frame;

		m_video_array.get_video(m_random_generator.get_random_size_t(0, m_video_array.get_number_of_videos()))->read(frame);
		
	}
	
}

void VideoPlayer::display_random_video()
{
	cv::namedWindow("window", cv::WINDOW_KEEPRATIO);

    while (1)
    {
        cv::Mat frame;
        // Mat object is a basic image container. frame is an object of Mat.

        m_video_array.get_video(0)->read(frame);

        cv::imshow("window", frame);
        // first argument: name of the window.
        // second argument: image to be shown(Mat object).

        if (cv::waitKey(50 / 10) == 27) // Wait for 'esc' key press to exit
        {
            break;
        }
    }

}

cv::Mat VideoPlayer::get_image()
{
    cv::Mat frame;
    m_video_array.get_video(m_video_array.get_number_of_videos())->read(frame);
    return frame;
}

cv::Mat VideoPlayer::get_random_image(size_t random_min, size_t random_max)
{
    cv::Mat frame;
    m_video_array.get_video(m_random_generator.get_random_size_t(random_min, random_max))->read(frame);
    return frame;
}

std::vector<cv::Mat> VideoPlayer::get_specific_part_of_video(size_t video_to_use, size_t starting_frame, size_t number_of_frames_to_use)
{
    std::vector<cv::Mat> frames;
    std::shared_ptr<cv::VideoCapture> video = m_video_array.get_video(video_to_use);

    if (!video->isOpened()) {
        std::cerr << "Error: Could not open video " << video_to_use << std::endl;
        return frames;
    }

    video->set(cv::CAP_PROP_POS_FRAMES, starting_frame);

    for (size_t i = 0; i < number_of_frames_to_use; ++i)
    {
        cv::Mat frame;
        if (!video->read(frame) || frame.empty()) {
            std::cerr << "Error: Could not read frame " << (starting_frame + i) << " from video " << video_to_use << std::endl;
            break;
        }
        frames.push_back(frame);
    }
    return frames;
}
