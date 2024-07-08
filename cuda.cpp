//#include <iostream>
//using namespace std;
//
//int main()
//{
//    cout << "Hello, World!";
//    return 0;
//}

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/cudaarithm.hpp>
#include <iostream>

using namespace std;
using namespace cv;
using namespace cv::cuda;

int main(int argc, char** argv) {
	Mat image_host = imread("D:/lena.png");//CPU的内存对象
	if (image_host.empty()) {
		cerr << "Could not read the image" << endl;
		return 1;
	}
	imshow("input", image_host);
	cout << "Hello world"<<endl;

	GpuMat image_device;
	image_device.upload(image_host);
	Mat gray_host;
	//cv::cvtColor(image_device, gray_device, COLOR_BGR2GRAY);//cuda加速的cvt版本=
	try {
		cv::cvtColor(image_host, gray_host, COLOR_BGR2GRAY);
	}
	catch (const Exception& e) {
		cout << "OpenCV Exception: " << e.what() << endl;
	}
	//Mat gray_host;
	//gray_device.download(gray_host);
	imshow("gray", gray_host);//注意：imshow显示不了GpuMat的对象
	waitKey(0);
	return 0;
}

//#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>
//#include <opencv2/cudaarithm.hpp>
//#include <iostream>
//
//using namespace std;
//using namespace cv;
//using namespace cv::cuda;
//
//int main()
//{
//	// OpenCV版本号
//    cout << "OpenCV_Version: " << CV_VERSION << endl;
//    // CUDA
//    int num_devices = getCudaEnabledDeviceCount();
//    if (num_devices)
//        cout << "CUDA is available, num_devices:" << num_devices << endl;
//    else
//        cout << "CUDA is not available." << endl;
//    //读取图片
//    Mat img = imread("D:/lena.png");
//
//    imshow("picture", img);
//    waitKey(0);
//    return 0;
//}


