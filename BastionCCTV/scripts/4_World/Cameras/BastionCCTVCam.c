class BastionCCTVCam : Camera {
	void BastionCCTVCam() {
		SetEventMask( EntityEvent.FRAME );
	}

	void OnUpdate( float timeSlice ) {
		Input input = GetGame().GetInput();

		float yawDiff = input.LocalValue("UAAimLeft") - input.LocalValue("UAAimRight");
		float pitchDiff = input.LocalValue("UAAimDown") - input.LocalValue("UAAimUp");
		vector orientation = GetOrientation();
		orientation[0] = orientation[0] - Math.RAD2DEG * yawDiff * timeSlice;
		orientation[1] = orientation[1] - Math.RAD2DEG * pitchDiff * timeSlice;
		if( orientation[1] < -89 ) {
			orientation[1] = -89;
		}
		if( orientation[1] > 89 ) {
			orientation[1] = 89;
		}
		
		SetOrientation(orientation);
	}
}
