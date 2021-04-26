
// TicTacDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TicTac.h"
#include "TicTacDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTicTacDlg dialog



CTicTacDlg::CTicTacDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TICTAC_DIALOG, pParent)
	, m_btn_topleft(0)
	, m_btn_topmid(0)
	, m_btn_toprgt(0)
	, m_btn_midleft(0)
	, m_btn_midmid(0)
	, m_btn_midrgt(0)
	, m_btn_dwnleft(0)
	, m_btn_dwnmid(0)
	, m_btn_dwnrgt(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_iplayer = 1;	
}

void CTicTacDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_BTN_TOPLEFT, m_btnTopLeft);
	//DDX_Control(pDX, IDC_BTN_TOPMID, m_btnTopMid);
	//DDX_Control(pDX, IDC_BTN_TOPRGT, m_btnTopRight);
	
}

BEGIN_MESSAGE_MAP(CTicTacDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_TOPLEFT, &CTicTacDlg::OnBnClickedBtnTopleft)
	ON_BN_CLICKED(IDC_BTN_TOPMID, &CTicTacDlg::OnBnClickedBtnTopmid)
	ON_BN_CLICKED(IDC_BTN_TOPRGT, &CTicTacDlg::OnBnClickedBtnToprgt)
	ON_BN_CLICKED(IDC_BTN_MIDLEFT, &CTicTacDlg::OnBnClickedBtnMidleft)
	ON_BN_CLICKED(IDC_BTN_MIDMID, &CTicTacDlg::OnBnClickedBtnMidmid)
	ON_BN_CLICKED(IDC_BTN_MIDRGT, &CTicTacDlg::OnBnClickedBtnMidrgt)
	ON_BN_CLICKED(IDC_BTN_DWNLEFT, &CTicTacDlg::OnBnClickedBtnDwnleft)
	ON_BN_CLICKED(IDC_BTN_DWNMID, &CTicTacDlg::OnBnClickedBtnDwnmid)
	ON_BN_CLICKED(IDC_BTN_DWNRGT, &CTicTacDlg::OnBnClickedBtnDwnrgt)
	ON_BN_CLICKED(IDC_BUTTON2, &CTicTacDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CTicTacDlg message handlers

BOOL CTicTacDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTicTacDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTicTacDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTicTacDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTicTacDlg::OnBnClickedBtnTopleft()
{
	// TODO: Add your control notification handler code here
			
	CBitmap bmp;

	if (m_iplayer % 2 == 0) {
		bmp.LoadBitmap(IDB_BITMAP2);
		m_btn_topleft = 1;
	}
	else {
		bmp.LoadBitmap(IDB_BITMAP3);
		m_btn_topleft = 2;
	}
	
	
	
	

	CButton* pButton = (CButton*)GetDlgItem(IDC_BTN_TOPLEFT);

	pButton->ModifyStyle(0, BS_BITMAP);

	pButton->SetBitmap(bmp);
	GetDlgItem(IDC_BTN_TOPLEFT)->EnableWindow(FALSE);
	if (results() == 1) {
		MessageBox(L"Player 2 Win", L"Result");
	}
	else if (results() == 2) {
		MessageBox(L"Player 1 Win", L"Result");
	}
	else if (m_iplayer == 9) {
		MessageBox(L"Its a Tie", L"Result");
	}
	m_iplayer++;
}


void CTicTacDlg::OnBnClickedBtnTopmid()
{
	// TODO: Add your control notification handler code here
	
	
	CBitmap bmp;
	if (m_iplayer % 2 == 0) {
		bmp.LoadBitmap(IDB_BITMAP2);
		m_btn_topmid = 1;
	}
	else {
		bmp.LoadBitmap(IDB_BITMAP3);
		m_btn_topmid = 2;
	}


	
	CButton* pButton = (CButton*)GetDlgItem(IDC_BTN_TOPMID);
	pButton->ModifyStyle(0, BS_BITMAP);
	pButton->SetBitmap(bmp);
	GetDlgItem(IDC_BTN_TOPMID)->EnableWindow(FALSE);
	if (results() == 1) {
		MessageBox(L"Player 2 Win", L"Result");
	}
	else if (results() == 2) {
		MessageBox(L"Player 1 Win", L"Result");
	}
	else if (m_iplayer == 9) {
		MessageBox(L"Its a Tie", L"Result");
	}
	m_iplayer++;
}


void CTicTacDlg::OnBnClickedBtnToprgt()
{
	// TODO: Add your control notification handler code here
	
	
	CBitmap bmp;
	if (m_iplayer % 2 == 0) {
		bmp.LoadBitmap(IDB_BITMAP2);
		m_btn_toprgt = 1;
	}
	else {
		bmp.LoadBitmap(IDB_BITMAP3);
		m_btn_toprgt = 2;
	}


	
	CButton* pButton = (CButton*)GetDlgItem(IDC_BTN_TOPRGT);
	pButton->ModifyStyle(0, BS_BITMAP);
	pButton->SetBitmap(bmp);
	GetDlgItem(IDC_BTN_TOPRGT)->EnableWindow(FALSE);
	if (results() == 1) {
		MessageBox(L"Player 2 Win", L"Result");
	}
	else if (results() == 2) {
		MessageBox(L"Player 1 Win", L"Result");
	}
	else if (m_iplayer == 9) {
		MessageBox(L"Its a Tie", L"Result");
	}
	m_iplayer++;
}


void CTicTacDlg::OnBnClickedBtnMidleft()
{
	// TODO: Add your control notification handler code here
	
	
	CBitmap bmp;
	if (m_iplayer % 2 == 0) {
		bmp.LoadBitmap(IDB_BITMAP2);
		m_btn_midleft = 1;
	}
	else {
		bmp.LoadBitmap(IDB_BITMAP3);
		m_btn_midleft = 2;
	}


	
	CButton* pButton = (CButton*)GetDlgItem(IDC_BTN_MIDLEFT);
	pButton->ModifyStyle(0, BS_BITMAP);
	pButton->SetBitmap(bmp);
	GetDlgItem(IDC_BTN_MIDLEFT)->EnableWindow(FALSE);
	if (results() == 1) {
		MessageBox(L"Player 2 Win", L"Result");
	}
	else if (results() == 2) {
		MessageBox(L"Player 1 Win", L"Result");
	}
	else if (m_iplayer == 9) {
		MessageBox(L"Its a Tie", L"Result");
	}
	m_iplayer++;
}


void CTicTacDlg::OnBnClickedBtnMidmid()
{
	// TODO: Add your control notification handler code here
	
	
	CBitmap bmp;
	if (m_iplayer % 2 == 0) {
		bmp.LoadBitmap(IDB_BITMAP2);
		m_btn_midmid = 1;
	}
	else {
		bmp.LoadBitmap(IDB_BITMAP3);
		m_btn_midmid = 2;
	}


	
	CButton* pButton = (CButton*)GetDlgItem(IDC_BTN_MIDMID);
	pButton->ModifyStyle(0, BS_BITMAP);
	pButton->SetBitmap(bmp);
	GetDlgItem(IDC_BTN_MIDMID)->EnableWindow(FALSE);
	if (results() == 1) {
		MessageBox(L"Player 2 Win", L"Result");
	}
	else if (results() == 2) {
		MessageBox(L"Player 1 Win", L"Result");
	}
	else if (m_iplayer == 9) {
		MessageBox(L"Its a Tie", L"Result");
	}
	m_iplayer++;
}


void CTicTacDlg::OnBnClickedBtnMidrgt()
{
	// TODO: Add your control notification handler code here
	
	
	CBitmap bmp;
	if (m_iplayer % 2 == 0) {
		bmp.LoadBitmap(IDB_BITMAP2);
		m_btn_midrgt = 1;
	}
	else {
		bmp.LoadBitmap(IDB_BITMAP3);
		m_btn_midrgt = 2;
	}


	
	CButton* pButton = (CButton*)GetDlgItem(IDC_BTN_MIDRGT);
	pButton->ModifyStyle(0, BS_BITMAP);
	pButton->SetBitmap(bmp);
	GetDlgItem(IDC_BTN_MIDRGT)->EnableWindow(FALSE);
	if (results() == 1) {
		MessageBox(L"Player 2 Win", L"Result");
	}
	else if (results() == 2) {
		MessageBox(L"Player 1 Win", L"Result");
	}
	else if (m_iplayer == 9) {
		MessageBox(L"Its a Tie", L"Result");
	}
	m_iplayer++;
}


void CTicTacDlg::OnBnClickedBtnDwnleft()
{
	// TODO: Add your control notification handler code here
	
	
	CBitmap bmp;
	if (m_iplayer % 2 == 0) {
		bmp.LoadBitmap(IDB_BITMAP2);
		m_btn_dwnleft = 1;
	}
	else {
		bmp.LoadBitmap(IDB_BITMAP3);
		m_btn_dwnleft = 2;
	}


	
	CButton* pButton = (CButton*)GetDlgItem(IDC_BTN_DWNLEFT);
	pButton->ModifyStyle(0, BS_BITMAP);
	pButton->SetBitmap(bmp);
	GetDlgItem(IDC_BTN_DWNLEFT)->EnableWindow(FALSE);
	if (results() == 1) {
		MessageBox(L"Player 2 Win", L"Result");
	}
	else if (results() == 2) {
		MessageBox(L"Player 1 Win", L"Result");
	}
	else if (m_iplayer == 9) {
		MessageBox(L"Its a Tie", L"Result");
	}
	m_iplayer++;
}


void CTicTacDlg::OnBnClickedBtnDwnmid()
{
	// TODO: Add your control notification handler code here
	
	
	CBitmap bmp;
	if (m_iplayer % 2 == 0) {
		bmp.LoadBitmap(IDB_BITMAP2);
		m_btn_dwnmid = 1;
	}
	else {
		bmp.LoadBitmap(IDB_BITMAP3);
		m_btn_dwnmid = 2;
	}


	
	CButton* pButton = (CButton*)GetDlgItem(IDC_BTN_DWNMID);
	pButton->ModifyStyle(0, BS_BITMAP);
	pButton->SetBitmap(bmp);
	GetDlgItem(IDC_BTN_DWNMID)->EnableWindow(FALSE);
	if (results() == 1) {
		MessageBox(L"Player 2 Win", L"Result");
	}
	else if (results() == 2) {
		MessageBox(L"Player 1 Win", L"Result");
	}
	else if (m_iplayer == 9) {
		MessageBox(L"Its a Tie", L"Result");
	}
	m_iplayer++;
}


void CTicTacDlg::OnBnClickedBtnDwnrgt()
{
	// TODO: Add your control notification handler code here
	
	CBitmap bmp;
	if (m_iplayer % 2 == 0) {
		bmp.LoadBitmap(IDB_BITMAP2);
		m_btn_dwnrgt = 1;
	}
	else {
		bmp.LoadBitmap(IDB_BITMAP3);
		m_btn_dwnrgt = 2;
	}


	
	CButton* pButton = (CButton*)GetDlgItem(IDC_BTN_DWNRGT);
	pButton->ModifyStyle(0, BS_BITMAP);
	pButton->SetBitmap(bmp);
	GetDlgItem(IDC_BTN_DWNRGT)->EnableWindow(FALSE);
	if (results() == 1) {
		MessageBox(L"Player 2 Win", L"Result");
	}
	else if (results() == 2) {
		MessageBox(L"Player 1 Win", L"Result");
	}
	else if (m_iplayer == 9) {
		MessageBox(L"Its a Tie", L"Result");
	}
	m_iplayer++;
}
int CTicTacDlg::results() {
	/*m_btn_topleft == 1
		m_btn_topmid == 1
		m_btn_toprgt == 1
		m_btn_midleft == 1
		m_btn_midmid == 1
		m_btn_midrgt == 1
		m_btn_dwnleft == 1
		m_btn_dwnmid == 1
		m_btn_dwnrgt == 1*/

	if (m_btn_topleft == 1 && m_btn_topmid == 1 && m_btn_toprgt == 1) {
		return 1;
	}
	if (m_btn_dwnleft == 1 && m_btn_dwnmid == 1 && m_btn_dwnrgt == 1) {
		return 1;
	}
	if (m_btn_midleft == 1 && m_btn_midmid == 1 && m_btn_midrgt == 1) {
		return 1;
	}

	if (m_btn_topmid == 1 && m_btn_midmid == 1 && m_btn_dwnmid == 1) {
		return 1;
	}

	if (m_btn_topleft == 1 && m_btn_midleft == 1 && m_btn_dwnleft == 1) {
		return 1;
	}
	if (m_btn_toprgt == 1 && m_btn_midrgt == 1 && m_btn_dwnrgt == 1) {
		return 1;
	}

	if (m_btn_topleft == 1 && m_btn_midmid == 1 && m_btn_dwnrgt == 1) {
		return 1;
	}

	if (m_btn_toprgt == 1 && m_btn_midmid == 1 && m_btn_dwnleft == 1) {
		return 1;
	}
	///////

	if (m_btn_topleft == 2 && m_btn_topmid == 2 && m_btn_toprgt == 2) {
		return 2;
	}
	if (m_btn_dwnleft == 2 && m_btn_dwnmid == 2 && m_btn_dwnrgt == 2) {
		return 2;
	}
	if (m_btn_midleft == 2 && m_btn_midmid == 2 && m_btn_midrgt == 2) {
		return 2;
	}

	if (m_btn_topmid == 2 && m_btn_midmid == 2 && m_btn_dwnmid == 2) {
		return 2;
	}

	if (m_btn_topleft == 2 && m_btn_midleft == 2 && m_btn_dwnleft == 2) {
		return 2;
	}
	if (m_btn_toprgt == 2 && m_btn_midrgt == 2 && m_btn_dwnrgt == 2) {
		return 2;
	}

	if (m_btn_topleft == 2 && m_btn_midmid == 2 && m_btn_dwnrgt == 2) {
		return 2;
	}

	if (m_btn_toprgt == 2 && m_btn_midmid == 2 && m_btn_dwnleft == 2) {
		return 2;
	}


	return 0;
	


}

void CTicTacDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	m_iplayer = 1;
	m_btn_topleft = 0;
	m_btn_topmid = 0;
	m_btn_toprgt = 0;
	m_btn_midleft = 0;
	m_btn_midmid = 0;
	m_btn_midrgt = 0;
	m_btn_dwnleft = 0;
	m_btn_dwnmid = 0;
	m_btn_dwnrgt = 0;
	CButton* pButton = NULL;
	GetDlgItem(IDC_BTN_TOPLEFT)->EnableWindow(TRUE);
	pButton = (CButton*)GetDlgItem(IDC_BTN_TOPLEFT);
	pButton->ModifyStyle(0, BS_BITMAP);
	pButton->SetBitmap(NULL);
	pButton = NULL;
	GetDlgItem(IDC_BTN_TOPMID)->EnableWindow(TRUE);
	pButton = (CButton*)GetDlgItem(IDC_BTN_TOPMID);
	pButton->ModifyStyle(0, BS_BITMAP);
	pButton->SetBitmap(NULL);
	pButton = NULL;
	GetDlgItem(IDC_BTN_TOPRGT)->EnableWindow(TRUE);
	pButton = (CButton*)GetDlgItem(IDC_BTN_TOPRGT);
	pButton->ModifyStyle(0, BS_BITMAP);
	pButton->SetBitmap(NULL);
	pButton = NULL;
	GetDlgItem(IDC_BTN_MIDLEFT)->EnableWindow(TRUE);
	pButton = (CButton*)GetDlgItem(IDC_BTN_MIDLEFT);
	pButton->ModifyStyle(0, BS_BITMAP);
	pButton->SetBitmap(NULL);
	pButton = NULL;
	GetDlgItem(IDC_BTN_MIDMID)->EnableWindow(TRUE);
	pButton = (CButton*)GetDlgItem(IDC_BTN_MIDMID);
	pButton->ModifyStyle(0, BS_BITMAP);
	pButton->SetBitmap(NULL);
	pButton = NULL;
	GetDlgItem(IDC_BTN_MIDRGT)->EnableWindow(TRUE);
	pButton = (CButton*)GetDlgItem(IDC_BTN_MIDRGT);
	pButton->ModifyStyle(0, BS_BITMAP);
	pButton->SetBitmap(NULL);
	pButton = NULL;
	GetDlgItem(IDC_BTN_DWNLEFT)->EnableWindow(TRUE);
	pButton = (CButton*)GetDlgItem(IDC_BTN_DWNLEFT);
	pButton->ModifyStyle(0, BS_BITMAP);
	pButton->SetBitmap(NULL);
	pButton = NULL;
	GetDlgItem(IDC_BTN_DWNMID)->EnableWindow(TRUE);
	pButton = (CButton*)GetDlgItem(IDC_BTN_DWNMID);
	pButton->ModifyStyle(0, BS_BITMAP);
	pButton->SetBitmap(NULL);
	pButton = NULL;
	GetDlgItem(IDC_BTN_DWNRGT)->EnableWindow(TRUE);
	pButton = (CButton*)GetDlgItem(IDC_BTN_DWNRGT);
	pButton->ModifyStyle(0, BS_BITMAP);
	pButton->SetBitmap(NULL);
	

}
