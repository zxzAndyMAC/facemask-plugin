/*
* Face Masks for SlOBS
* smll - streamlabs machine learning library
*
* Copyright (C) 2017 General Workings Inc
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
*/
#pragma once

#include "Kalman.hpp"

namespace smll {

	class SingleValueKalman
	{
	public:
		
		SingleValueKalman();
		~SingleValueKalman();

		void Init(double val);
		double Update(double val);

		// This is like a smoothing factor
		// 1.0 is good for normal use, bump up to 4.0 for really smooth
		// 1.0 is default
		void SetMeasurementNoiseCovariance(double mnc) {
			m_kf->set_R(mnc);
		}

	private:
		KalmanFilter<double, 1, 3>*	m_kf;

	};

}