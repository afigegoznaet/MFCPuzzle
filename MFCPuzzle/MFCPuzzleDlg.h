
// MFCPuzzleDlg.h : header file
//

#pragma once
#include <vector>

// CMFCPuzzleDlg dialog
class CMFCPuzzleDlg : public CDialogEx {
	// Construction
public:
	CMFCPuzzleDlg(CWnd *pParent = nullptr); // standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPUZZLE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange *pDX); // DDX/DDV support


	// Implementation
protected:
	HICON m_hIcon;

	std::vector<CButton *> buttonList;
	CFont l_font;
	int zeroButtonIndex{0};

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonTst();
};
