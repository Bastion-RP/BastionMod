class BastionCCTVCam : Camera {
    private float targetZoom = 1.0;

	void BastionCCTVCam() {
		SetEventMask( EntityEvent.FRAME );
        targetZoom = GetCurrentFOV();
	}

	override void EOnFrame(IEntity other, float timeSlice) {
		Input input = GetGame().GetInput();

        float mwheelup = input.LocalValue("UAPrevAction");
        float mwheeldown = input.LocalValue("UANextAction");

		if ( mwheelup != 0.0 ) {
			targetZoom -= mwheelup * 0.02;
			if ( targetZoom < 0.2 )  {
				targetZoom = 0.2;
			}
		}
		if ( mwheeldown != 0.0 ) {
			targetZoom += mwheeldown * 0.02;
			if ( targetZoom > 1.0 )  {
				targetZoom = 1.0;
			}
		}
        if ( GetCurrentFOV() != targetZoom )  {
            SetFOV( targetZoom );
        }

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
