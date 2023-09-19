#include <librealsense2/rs.hpp>
#include <opencv2/opencv.hpp>

int main() {
    // Initialize realsense
    rs2::pipeline pipe;
    rs2::config cfg;

    cfg.enable_stream(RS2_STREAM_DEPTH, 640, 480, RS2_FORMAT_Z16, 30);
    cfg.enable_stream(RS2_STREAM_COLOR, 640, 480, RS2_FORMAT_BGR8, 30);

    pipe.start(cfg);

    // Main loop
    while (true) {
        rs2::frameset frames = pipe.wait_for_frames();
        rs2::depth_frame depth_frame = frames.get_depth_frame();
        rs2::video_frame color_frame = frames.get_color_frame();

        // Convert to OpenCV Mat format
        cv::Mat depth_image(cv::Size(640, 480), CV_16U, (void*)depth_frame.get_data(), cv::Mat::AUTO_STEP);
        cv::Mat color_image(cv::Size(640, 480), CV_8UC3, (void*)color_frame.get_data(), cv::Mat::AUTO_STEP);

        // Visualize with OpenCV
        cv::imshow("Depth Image", depth_image);
        cv::imshow("Color Image", color_image);

        // Close program when pressing ESC
        if (cv::waitKey(1) == 27) {
            break;
        }
    }

    return 0;
}
