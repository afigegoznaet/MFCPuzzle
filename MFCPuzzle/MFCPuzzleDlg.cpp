
// MFCPuzzleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCPuzzle.h"
#include "MFCPuzzleDlg.h"
#include "afxdialogex.h"
#include <sstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx {
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange *pDX); // DDX/DDV support

	// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX) {}

void CAboutDlg::DoDataExchange(CDataExchange *pDX) {
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCPuzzleDlg dialog


CMFCPuzzleDlg::CMFCPuzzleDlg(CWnd *pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPUZZLE_DIALOG, pParent) {
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCPuzzleDlg::DoDataExchange(CDataExchange *pDX) {
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCPuzzleDlg, CDialogEx)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_BUTTON_TST, &CMFCPuzzleDlg::OnBnClickedButtonTst)
END_MESSAGE_MAP()


// CMFCPuzzleDlg message handlers

BOOL CMFCPuzzleDlg::OnInitDialog() {
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu *pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr) {
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty()) {
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);  // Set big icon
	SetIcon(m_hIcon, FALSE); // Set small icon

	// TODO: Add extra initialization here


	l_font.CreateFont(96, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, 0,
					  OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
					  ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_ROMAN,
					  L"Times New Roman");
	SetFont(&l_font);

	buttonList.push_back((CButton *)GetDlgItem(IDC_BUTTON0));
	buttonList.push_back((CButton *)GetDlgItem(IDC_BUTTON1));
	buttonList.push_back((CButton *)GetDlgItem(IDC_BUTTON2));
	buttonList.push_back((CButton *)GetDlgItem(IDC_BUTTON3));
	buttonList.push_back((CButton *)GetDlgItem(IDC_BUTTON4));
	buttonList.push_back((CButton *)GetDlgItem(IDC_BUTTON5));
	buttonList.push_back((CButton *)GetDlgItem(IDC_BUTTON6));
	buttonList.push_back((CButton *)GetDlgItem(IDC_BUTTON7));
	buttonList.push_back((CButton *)GetDlgItem(IDC_BUTTON8));
	buttonList.push_back((CButton *)GetDlgItem(IDC_BUTTON9));
	buttonList.push_back((CButton *)GetDlgItem(IDC_BUTTON10));
	buttonList.push_back((CButton *)GetDlgItem(IDC_BUTTON11));
	buttonList.push_back((CButton *)GetDlgItem(IDC_BUTTON12));
	buttonList.push_back((CButton *)GetDlgItem(IDC_BUTTON13));
	buttonList.push_back((CButton *)GetDlgItem(IDC_BUTTON14));
	buttonList.push_back((CButton *)GetDlgItem(IDC_BUTTON15));

	for (auto &but : buttonList) {
		but->SetFont(&l_font);
	}


	return TRUE; // return TRUE  unless you set the focus to a control
}

void CMFCPuzzleDlg::OnSysCommand(UINT nID, LPARAM lParam) {
	if ((nID & 0xFFF0) == IDM_ABOUTBOX) {
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	} else {
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCPuzzleDlg::OnPaint() {
	if (IsIconic()) {
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND,
					reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	} else {
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user
// drags
//  the minimized window.
HCURSOR CMFCPuzzleDlg::OnQueryDragIcon() {
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCPuzzleDlg::OnBnClickedButtonTst() {
	int next = rand() % 16;
	CString strText;
	buttonList[next]->GetWindowText(strText);
	buttonList[zeroButtonIndex]->SetWindowText(strText);
	buttonList[next]->SetWindowText(L" ");
	zeroButtonIndex = next;
	// for (int i = 0; i < 10; i++) { }
}
