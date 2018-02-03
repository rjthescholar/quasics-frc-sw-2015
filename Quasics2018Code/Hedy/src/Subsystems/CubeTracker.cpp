/*
 * CubeTracker.cpp
 *
 *  Created on: Jan 27, 2018
 *      Author: dxc101
 */

#include "CubeTracker.h"

#define IMG_WIDTH	320
#define IMG_HEIGHT	240

CubeTracker::CubeTracker() : frc::Subsystem("CubeTracker") {
	/*
	 * The following code is based on an example provided at:
	 * https://github.com/wpilibsuite/roboRIOVisionExamples/tree/master/2018/2018VisionSampleCPP
	 */
	cs::UsbCamera camera = frc::CameraServer::GetInstance()->StartAutomaticCapture();
	camera.SetResolution(IMG_WIDTH, IMG_HEIGHT);
	m_lock = new std::mutex;

	visionTrackingTask = new frc::VisionRunner<grip::Vision>(
			camera, new grip::Vision(),
			[&](grip::Vision& pipeline)
			{
				//If we have at least 1 contour, we might have a target
				const auto * filterCountoursOutput = pipeline.GetFilterContoursOutput();
 				if (filterCountoursOutput->size() > 0)
				{
					int bestArea = 0;
					cv::Rect bestRectangle;
					//Iterate through list of found contours, and find the biggest one.
					for(unsigned int i=0; i < pipeline.GetFilterContoursOutput()->size(); i++)
					{
						const std::vector<cv::Point> & countourPoints = (*filterCountoursOutput)[i];
						const cv::Rect rectangle1 = cv::boundingRect(cv::Mat(countourPoints));
						const int area = rectangle1.width * rectangle1.height;
						if (area > bestArea) {
							bestArea = area;
							bestRectangle = rectangle1;
						}
					}
					m_lock->lock();
					currentRect = bestRectangle;
					m_lock->unlock();
				}
			});
	m_visionThread = new std::thread(&CubeTracker::visionExecuter, this);
}

void CubeTracker::visionExecuter()
{
	std::cerr << "Starting up vision execution" << std::endl;
	visionTrackingTask->RunForever();
}

cv::Rect CubeTracker::getCurrentRect() {
	cv::Rect result;
	m_lock->lock();
	result = currentRect;
	m_lock->unlock();
	return result;
}
