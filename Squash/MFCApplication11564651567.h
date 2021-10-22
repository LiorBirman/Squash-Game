
// MFCApplication11564651567.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCApplication11564651567App:
// See MFCApplication11564651567.cpp for the implementation of this class
//

class CMFCApplication11564651567App : public CWinApp
{
public:
	CMFCApplication11564651567App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication11564651567App theApp;
