
// TicTacDlg.h : header file
//

#pragma once


// CTicTacDlg dialog
class CTicTacDlg : public CDialogEx
{
// Construction
public:
	CTicTacDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TICTAC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	int m_iplayer;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnTopleft();
	afx_msg void OnBnClickedBtnTopmid();
	afx_msg void OnBnClickedBtnToprgt();
	afx_msg void OnBnClickedBtnMidleft();
	afx_msg void OnBnClickedBtnMidmid();
	afx_msg void OnBnClickedBtnMidrgt();
	afx_msg void OnBnClickedBtnDwnleft();
	afx_msg void OnBnClickedBtnDwnmid();
	afx_msg void OnBnClickedBtnDwnrgt();
	int results();
	/*CButton m_btnTopLeft;
	CButton m_btnTopMid;
	CButton m_btnTopRight;*/
	int m_btn_topleft;
	int m_btn_topmid;
	int m_btn_toprgt;
	int m_btn_midleft;
	int m_btn_midmid;
	int m_btn_midrgt;
	int m_btn_dwnleft;
	int m_btn_dwnmid;
	int m_btn_dwnrgt;
	afx_msg void OnBnClickedButton2();
};
