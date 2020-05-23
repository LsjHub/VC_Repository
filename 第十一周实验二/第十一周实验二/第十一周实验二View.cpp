
// 第十一周实验二View.cpp : C第十一周实验二View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第十一周实验二.h"
#endif

#include "第十一周实验二Set.h"
#include "第十一周实验二Doc.h"
#include "第十一周实验二View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第十一周实验二View

IMPLEMENT_DYNCREATE(C第十一周实验二View, CRecordView)

BEGIN_MESSAGE_MAP(C第十一周实验二View, CRecordView)
	ON_COMMAND(ID_32771, &C第十一周实验二View::On32771)
END_MESSAGE_MAP()

// C第十一周实验二View 构造/析构

C第十一周实验二View::C第十一周实验二View()
	: CRecordView(IDD_MY_FORM)
	, ID(0)
	, name(_T(""))
	, number(_T(""))
	, age(_T(""))
	, phone(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

C第十一周实验二View::~C第十一周实验二View()
{
}

void C第十一周实验二View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column4);
	Invalidate();
}

BOOL C第十一周实验二View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void C第十一周实验二View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_第十一周实验二Set;
	CRecordView::OnInitialUpdate();

}


// C第十一周实验二View 诊断

#ifdef _DEBUG
void C第十一周实验二View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C第十一周实验二View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C第十一周实验二Doc* C第十一周实验二View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第十一周实验二Doc)));
	return (C第十一周实验二Doc*)m_pDocument;
}
#endif //_DEBUG


// C第十一周实验二View 数据库支持
CRecordset* C第十一周实验二View::OnGetRecordset()
{
	return m_pSet;
}



// C第十一周实验二View 消息处理程序


void C第十一周实验二View::On32771()
{
	// TODO: 在此添加命令处理程序代码
	CString s;
	s = m_pSet->column5;
	CImage img;
	CDC* pDC = GetDC();
	img.Load(s);
	img.Draw(pDC->m_hDC, 300, 200, img.GetWidth(), img.GetHeight());
	ReleaseDC(pDC);
}
