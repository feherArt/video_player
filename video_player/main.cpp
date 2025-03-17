#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <string>
#include <memory>

#include "RandomNumber.h"

#include "VideoArray.h"
#include "VideoPlayer.h"
#include "VideoEditor.h"


int main() 
{
    //RandomNumber random_generator{};
    //VideoArray video_array(2, ".mp4");

    //VideoPlayer video_player{ 2, ".mp4" };

    //video_player.play_random_videos(300);
    //video_player.display_random_video();
    
    cv::Size m_full_hd{ 2500, 1350 };
    auto m_fourcc{ cv::VideoWriter::fourcc('H', '2', '6', '4') };
    double m_video_witer_frame_rate{ 16.0f };
    const std::string& m_output_file_name{ "output.mp4" };
    cv::VideoWriter m_video_writer{ m_output_file_name, m_fourcc, m_video_witer_frame_rate, m_full_hd };

    std::cout << "API:\t" << m_video_writer.getBackendName() << std::endl;
   /*for (size_t i{}; i < 30000; ++i)
    {
        cv::Mat frame;
        m_video_writer.write(video_player.get_random_image(0, 1));
    }*/
    size_t number_of_videos{ 1 };
    VideoEditor video_editor{ number_of_videos, ".mov" };

    /*for (size_t i{}; i < 3; ++i)
    {
        std::vector<cv::Mat> frames{ video_player.get_specific_part_of_video(0, 10, 100) };

        for (const auto& frame : frames)
            m_video_writer.write(frame);
    }*/

    //std::vector<std::vector<cv::Mat>> two_dimensional_vector{ video_editor.total_random_editing(1500, 25) };
   /* for (const auto& vector : two_dimensional_vector)
        for (const auto& frame : vector)
            m_video_writer.write(frame);


    
    */

    //std::vector<cv::Mat> frames{ video_editor.total_random_editing_one_dimensional(1000, 20)};
    std::vector<std::vector<cv::Mat>> two_dimensional_vector{ video_editor.total_random_editing_variable_lenght(50, 200)};
    for (const auto& vector : two_dimensional_vector)
        for (const auto& frame : vector)
            m_video_writer.write(frame);

    m_video_writer.release(); 

    //return 0;
}

