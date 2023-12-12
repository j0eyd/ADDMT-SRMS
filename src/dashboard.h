#pragma once
#include "User.h"
#include "Lecture.h"
#include "Grade.h"
#include "Teacher.h"

namespace cs361 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for dashboard
	/// </summary>
	public ref class dashboard : public System::Windows::Forms::Form
	{
	public:
		dashboard(User^ user)
		{
			InitializeComponent();
			this->user = user;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~dashboard()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btnLogout;
	private: System::Windows::Forms::Button^ btnSGrades;

	private: System::Windows::Forms::Button^ btnSCourses;



	private: System::Windows::Forms::Button^ btnSDashboard;

	private: System::Windows::Forms::Label^ lbAppTitle;
	private: System::Windows::Forms::Panel^ pnlStudentSidebar;
	private: System::Windows::Forms::Button^ btnSAttend;

	private: System::Windows::Forms::Panel^ pnlTeacherSidebar;


	private: System::Windows::Forms::Button^ btnTDashboard;
	private: System::Windows::Forms::Button^ btnTSearch;


	private: System::Windows::Forms::Button^ btnTCourses;
	private: System::Windows::Forms::Button^ btnSReport;
	private: System::Windows::Forms::Button^ btnTReport;
	private: System::Windows::Forms::Panel^ pnlAdminSidebar;

	private: System::Windows::Forms::Button^ btnARegister;
	private: System::Windows::Forms::Button^ btnAReport;
	private: System::Windows::Forms::Button^ btnADashboard;
	private: System::Windows::Forms::Button^ btnASearch;
	private: System::Windows::Forms::Button^ btnACourses;
	private: System::Windows::Forms::Panel^ pnlDashboardProfile;
	private: System::Windows::Forms::Button^ btnConfirmBio;

	private: System::Windows::Forms::TextBox^ tbEditBio;
	private: System::Windows::Forms::Button^ btnEditBio;
	private: System::Windows::Forms::Label^ lbUserBio;
	private: System::Windows::Forms::Label^ lbBiography;
	private: System::Windows::Forms::Label^ lbUserName;
	private: System::Windows::Forms::Panel^ pnlSCourses;
	private: System::Windows::Forms::DataGridView^ dataAttendance;


	private: System::Windows::Forms::DataGridView^ dataGrades;




	private: System::Windows::Forms::ComboBox^ drpbxView;
	private: System::Windows::Forms::DataGridView^ dataCourses;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ clmCourseID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ clmCourse;
	private: System::Windows::Forms::Label^ lbCourses;
	private: System::Windows::Forms::Panel^ pnlReport;
	private: System::Windows::Forms::Button^ btnCourseBackup;
	private: System::Windows::Forms::TextBox^ tbCourseBackup;
	private: System::Windows::Forms::Label^ lbPrompt;
	private: System::Windows::Forms::Panel^ pnlRegisterStudent;
	private: System::Windows::Forms::Button^ btnRegisterSubmit;
	private: System::Windows::Forms::TextBox^ tbRegisterPswd;
	private: System::Windows::Forms::Label^ lbRegisterPswd;
	private: System::Windows::Forms::TextBox^ tbRegisterUsrnm;
	private: System::Windows::Forms::Label^ lbRegisterUsrnm;
	private: System::Windows::Forms::TextBox^ tbRegisterLN;
	private: System::Windows::Forms::Label^ lbRegisterLN;
	private: System::Windows::Forms::TextBox^ tbRegisterFN;
	private: System::Windows::Forms::Label^ lbRegisterFN;
	private: System::Windows::Forms::CheckBox^ cbShowCourses;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ clmAssignment;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ clmPoints;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ clmTotal;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ clmPercentage;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnLogout = (gcnew System::Windows::Forms::Button());
			this->btnSGrades = (gcnew System::Windows::Forms::Button());
			this->btnSCourses = (gcnew System::Windows::Forms::Button());
			this->btnSDashboard = (gcnew System::Windows::Forms::Button());
			this->lbAppTitle = (gcnew System::Windows::Forms::Label());
			this->pnlStudentSidebar = (gcnew System::Windows::Forms::Panel());
			this->btnSReport = (gcnew System::Windows::Forms::Button());
			this->btnSAttend = (gcnew System::Windows::Forms::Button());
			this->pnlTeacherSidebar = (gcnew System::Windows::Forms::Panel());
			this->btnTReport = (gcnew System::Windows::Forms::Button());
			this->btnTDashboard = (gcnew System::Windows::Forms::Button());
			this->btnTSearch = (gcnew System::Windows::Forms::Button());
			this->btnTCourses = (gcnew System::Windows::Forms::Button());
			this->pnlAdminSidebar = (gcnew System::Windows::Forms::Panel());
			this->btnARegister = (gcnew System::Windows::Forms::Button());
			this->btnAReport = (gcnew System::Windows::Forms::Button());
			this->btnADashboard = (gcnew System::Windows::Forms::Button());
			this->btnASearch = (gcnew System::Windows::Forms::Button());
			this->btnACourses = (gcnew System::Windows::Forms::Button());
			this->pnlDashboardProfile = (gcnew System::Windows::Forms::Panel());
			this->btnConfirmBio = (gcnew System::Windows::Forms::Button());
			this->btnEditBio = (gcnew System::Windows::Forms::Button());
			this->lbUserBio = (gcnew System::Windows::Forms::Label());
			this->lbBiography = (gcnew System::Windows::Forms::Label());
			this->lbUserName = (gcnew System::Windows::Forms::Label());
			this->tbEditBio = (gcnew System::Windows::Forms::TextBox());
			this->pnlSCourses = (gcnew System::Windows::Forms::Panel());
			this->cbShowCourses = (gcnew System::Windows::Forms::CheckBox());
			this->drpbxView = (gcnew System::Windows::Forms::ComboBox());
			this->dataCourses = (gcnew System::Windows::Forms::DataGridView());
			this->clmCourseID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clmCourse = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lbCourses = (gcnew System::Windows::Forms::Label());
			this->dataGrades = (gcnew System::Windows::Forms::DataGridView());
			this->clmAssignment = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clmPoints = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clmTotal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clmPercentage = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataAttendance = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->pnlReport = (gcnew System::Windows::Forms::Panel());
			this->btnCourseBackup = (gcnew System::Windows::Forms::Button());
			this->tbCourseBackup = (gcnew System::Windows::Forms::TextBox());
			this->lbPrompt = (gcnew System::Windows::Forms::Label());
			this->pnlRegisterStudent = (gcnew System::Windows::Forms::Panel());
			this->btnRegisterSubmit = (gcnew System::Windows::Forms::Button());
			this->tbRegisterPswd = (gcnew System::Windows::Forms::TextBox());
			this->lbRegisterPswd = (gcnew System::Windows::Forms::Label());
			this->tbRegisterUsrnm = (gcnew System::Windows::Forms::TextBox());
			this->lbRegisterUsrnm = (gcnew System::Windows::Forms::Label());
			this->tbRegisterLN = (gcnew System::Windows::Forms::TextBox());
			this->lbRegisterLN = (gcnew System::Windows::Forms::Label());
			this->tbRegisterFN = (gcnew System::Windows::Forms::TextBox());
			this->lbRegisterFN = (gcnew System::Windows::Forms::Label());
			this->pnlStudentSidebar->SuspendLayout();
			this->pnlTeacherSidebar->SuspendLayout();
			this->pnlAdminSidebar->SuspendLayout();
			this->pnlDashboardProfile->SuspendLayout();
			this->pnlSCourses->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataCourses))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrades))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataAttendance))->BeginInit();
			this->pnlReport->SuspendLayout();
			this->pnlRegisterStudent->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnLogout
			// 
			this->btnLogout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btnLogout->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLogout->Location = System::Drawing::Point(5, 913);
			this->btnLogout->Name = L"btnLogout";
			this->btnLogout->Size = System::Drawing::Size(150, 42);
			this->btnLogout->TabIndex = 19;
			this->btnLogout->Text = L"Logout";
			this->btnLogout->UseVisualStyleBackColor = true;
			this->btnLogout->Click += gcnew System::EventHandler(this, &dashboard::btnLogout_Click);
			// 
			// btnSGrades
			// 
			this->btnSGrades->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSGrades->Location = System::Drawing::Point(5, 99);
			this->btnSGrades->Name = L"btnSGrades";
			this->btnSGrades->Size = System::Drawing::Size(150, 42);
			this->btnSGrades->TabIndex = 17;
			this->btnSGrades->Text = L"Grades";
			this->btnSGrades->UseVisualStyleBackColor = true;
			this->btnSGrades->Click += gcnew System::EventHandler(this, &dashboard::btnSGrades_Click);
			// 
			// btnSCourses
			// 
			this->btnSCourses->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSCourses->Location = System::Drawing::Point(5, 52);
			this->btnSCourses->Name = L"btnSCourses";
			this->btnSCourses->Size = System::Drawing::Size(150, 42);
			this->btnSCourses->TabIndex = 16;
			this->btnSCourses->Text = L"Courses";
			this->btnSCourses->UseVisualStyleBackColor = true;
			this->btnSCourses->Click += gcnew System::EventHandler(this, &dashboard::btnSCourses_Click);
			// 
			// btnSDashboard
			// 
			this->btnSDashboard->FlatAppearance->BorderSize = 0;
			this->btnSDashboard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSDashboard->Location = System::Drawing::Point(5, 5);
			this->btnSDashboard->Name = L"btnSDashboard";
			this->btnSDashboard->Size = System::Drawing::Size(150, 42);
			this->btnSDashboard->TabIndex = 15;
			this->btnSDashboard->Text = L"Dashboard";
			this->btnSDashboard->UseVisualStyleBackColor = true;
			this->btnSDashboard->Click += gcnew System::EventHandler(this, &dashboard::btnSDashboard_Click);
			// 
			// lbAppTitle
			// 
			this->lbAppTitle->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbAppTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbAppTitle->Location = System::Drawing::Point(5, 5);
			this->lbAppTitle->Margin = System::Windows::Forms::Padding(0, 0, 3, 0);
			this->lbAppTitle->Name = L"lbAppTitle";
			this->lbAppTitle->Size = System::Drawing::Size(160, 160);
			this->lbAppTitle->TabIndex = 14;
			this->lbAppTitle->Text = L"SRMS";
			this->lbAppTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pnlStudentSidebar
			// 
			this->pnlStudentSidebar->Controls->Add(this->btnSReport);
			this->pnlStudentSidebar->Controls->Add(this->btnSAttend);
			this->pnlStudentSidebar->Controls->Add(this->btnSDashboard);
			this->pnlStudentSidebar->Controls->Add(this->btnSGrades);
			this->pnlStudentSidebar->Controls->Add(this->btnSCourses);
			this->pnlStudentSidebar->Location = System::Drawing::Point(5, 167);
			this->pnlStudentSidebar->Margin = System::Windows::Forms::Padding(2);
			this->pnlStudentSidebar->Name = L"pnlStudentSidebar";
			this->pnlStudentSidebar->Size = System::Drawing::Size(160, 240);
			this->pnlStudentSidebar->TabIndex = 20;
			this->pnlStudentSidebar->Visible = false;
			// 
			// btnSReport
			// 
			this->btnSReport->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSReport->Location = System::Drawing::Point(5, 193);
			this->btnSReport->Name = L"btnSReport";
			this->btnSReport->Size = System::Drawing::Size(150, 42);
			this->btnSReport->TabIndex = 22;
			this->btnSReport->Text = L"Backup";
			this->btnSReport->UseVisualStyleBackColor = true;
			this->btnSReport->Click += gcnew System::EventHandler(this, &dashboard::btnSReport_Click);
			// 
			// btnSAttend
			// 
			this->btnSAttend->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSAttend->Location = System::Drawing::Point(5, 146);
			this->btnSAttend->Name = L"btnSAttend";
			this->btnSAttend->Size = System::Drawing::Size(150, 42);
			this->btnSAttend->TabIndex = 21;
			this->btnSAttend->Text = L"Attendance";
			this->btnSAttend->UseVisualStyleBackColor = true;
			this->btnSAttend->Click += gcnew System::EventHandler(this, &dashboard::btnSAttend_Click);
			// 
			// pnlTeacherSidebar
			// 
			this->pnlTeacherSidebar->Controls->Add(this->btnTReport);
			this->pnlTeacherSidebar->Controls->Add(this->btnTDashboard);
			this->pnlTeacherSidebar->Controls->Add(this->btnTSearch);
			this->pnlTeacherSidebar->Controls->Add(this->btnTCourses);
			this->pnlTeacherSidebar->Location = System::Drawing::Point(5, 167);
			this->pnlTeacherSidebar->Margin = System::Windows::Forms::Padding(2);
			this->pnlTeacherSidebar->Name = L"pnlTeacherSidebar";
			this->pnlTeacherSidebar->Size = System::Drawing::Size(160, 193);
			this->pnlTeacherSidebar->TabIndex = 21;
			this->pnlTeacherSidebar->Visible = false;
			// 
			// btnTReport
			// 
			this->btnTReport->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnTReport->Location = System::Drawing::Point(5, 146);
			this->btnTReport->Name = L"btnTReport";
			this->btnTReport->Size = System::Drawing::Size(150, 42);
			this->btnTReport->TabIndex = 21;
			this->btnTReport->Text = L"Backup";
			this->btnTReport->UseVisualStyleBackColor = true;
			this->btnTReport->Click += gcnew System::EventHandler(this, &dashboard::btnTReport_Click);
			// 
			// btnTDashboard
			// 
			this->btnTDashboard->FlatAppearance->BorderSize = 0;
			this->btnTDashboard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnTDashboard->Location = System::Drawing::Point(5, 5);
			this->btnTDashboard->Name = L"btnTDashboard";
			this->btnTDashboard->Size = System::Drawing::Size(150, 42);
			this->btnTDashboard->TabIndex = 15;
			this->btnTDashboard->Text = L"Dashboard";
			this->btnTDashboard->UseVisualStyleBackColor = true;
			this->btnTDashboard->Click += gcnew System::EventHandler(this, &dashboard::btnTDashboard_Click);
			// 
			// btnTSearch
			// 
			this->btnTSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnTSearch->Location = System::Drawing::Point(5, 99);
			this->btnTSearch->Name = L"btnTSearch";
			this->btnTSearch->Size = System::Drawing::Size(150, 42);
			this->btnTSearch->TabIndex = 17;
			this->btnTSearch->Text = L"Search";
			this->btnTSearch->UseVisualStyleBackColor = true;
			this->btnTSearch->Click += gcnew System::EventHandler(this, &dashboard::btnTSearch_Click);
			// 
			// btnTCourses
			// 
			this->btnTCourses->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnTCourses->Location = System::Drawing::Point(5, 52);
			this->btnTCourses->Name = L"btnTCourses";
			this->btnTCourses->Size = System::Drawing::Size(150, 42);
			this->btnTCourses->TabIndex = 16;
			this->btnTCourses->Text = L"Courses";
			this->btnTCourses->UseVisualStyleBackColor = true;
			this->btnTCourses->Click += gcnew System::EventHandler(this, &dashboard::btnTCourses_Click);
			// 
			// pnlAdminSidebar
			// 
			this->pnlAdminSidebar->Controls->Add(this->btnARegister);
			this->pnlAdminSidebar->Controls->Add(this->btnAReport);
			this->pnlAdminSidebar->Controls->Add(this->btnADashboard);
			this->pnlAdminSidebar->Controls->Add(this->btnASearch);
			this->pnlAdminSidebar->Controls->Add(this->btnACourses);
			this->pnlAdminSidebar->Location = System::Drawing::Point(5, 167);
			this->pnlAdminSidebar->Margin = System::Windows::Forms::Padding(2);
			this->pnlAdminSidebar->Name = L"pnlAdminSidebar";
			this->pnlAdminSidebar->Size = System::Drawing::Size(160, 240);
			this->pnlAdminSidebar->TabIndex = 22;
			this->pnlAdminSidebar->Visible = false;
			// 
			// btnARegister
			// 
			this->btnARegister->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnARegister->Location = System::Drawing::Point(5, 146);
			this->btnARegister->Name = L"btnARegister";
			this->btnARegister->Size = System::Drawing::Size(150, 42);
			this->btnARegister->TabIndex = 23;
			this->btnARegister->Text = L"Register";
			this->btnARegister->UseVisualStyleBackColor = true;
			this->btnARegister->Click += gcnew System::EventHandler(this, &dashboard::btnARegister_Click);
			// 
			// btnAReport
			// 
			this->btnAReport->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAReport->Location = System::Drawing::Point(5, 193);
			this->btnAReport->Name = L"btnAReport";
			this->btnAReport->Size = System::Drawing::Size(150, 42);
			this->btnAReport->TabIndex = 21;
			this->btnAReport->Text = L"Backup";
			this->btnAReport->UseVisualStyleBackColor = true;
			this->btnAReport->Click += gcnew System::EventHandler(this, &dashboard::btnAReport_Click);
			// 
			// btnADashboard
			// 
			this->btnADashboard->FlatAppearance->BorderSize = 0;
			this->btnADashboard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnADashboard->Location = System::Drawing::Point(5, 5);
			this->btnADashboard->Name = L"btnADashboard";
			this->btnADashboard->Size = System::Drawing::Size(150, 42);
			this->btnADashboard->TabIndex = 15;
			this->btnADashboard->Text = L"Dashboard";
			this->btnADashboard->UseVisualStyleBackColor = true;
			this->btnADashboard->Click += gcnew System::EventHandler(this, &dashboard::btnADashboard_Click);
			// 
			// btnASearch
			// 
			this->btnASearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnASearch->Location = System::Drawing::Point(5, 99);
			this->btnASearch->Name = L"btnASearch";
			this->btnASearch->Size = System::Drawing::Size(150, 42);
			this->btnASearch->TabIndex = 17;
			this->btnASearch->Text = L"Search";
			this->btnASearch->UseVisualStyleBackColor = true;
			this->btnASearch->Click += gcnew System::EventHandler(this, &dashboard::btnASearch_Click);
			// 
			// btnACourses
			// 
			this->btnACourses->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnACourses->Location = System::Drawing::Point(5, 52);
			this->btnACourses->Name = L"btnACourses";
			this->btnACourses->Size = System::Drawing::Size(150, 42);
			this->btnACourses->TabIndex = 16;
			this->btnACourses->Text = L"Courses";
			this->btnACourses->UseVisualStyleBackColor = true;
			this->btnACourses->Click += gcnew System::EventHandler(this, &dashboard::btnACourses_Click);
			// 
			// pnlDashboardProfile
			// 
			this->pnlDashboardProfile->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pnlDashboardProfile->Controls->Add(this->btnConfirmBio);
			this->pnlDashboardProfile->Controls->Add(this->btnEditBio);
			this->pnlDashboardProfile->Controls->Add(this->lbUserBio);
			this->pnlDashboardProfile->Controls->Add(this->lbBiography);
			this->pnlDashboardProfile->Controls->Add(this->lbUserName);
			this->pnlDashboardProfile->Controls->Add(this->tbEditBio);
			this->pnlDashboardProfile->Location = System::Drawing::Point(170, 5);
			this->pnlDashboardProfile->Margin = System::Windows::Forms::Padding(2);
			this->pnlDashboardProfile->MinimumSize = System::Drawing::Size(760, 577);
			this->pnlDashboardProfile->Name = L"pnlDashboardProfile";
			this->pnlDashboardProfile->Size = System::Drawing::Size(1410, 950);
			this->pnlDashboardProfile->TabIndex = 23;
			// 
			// btnConfirmBio
			// 
			this->btnConfirmBio->AutoSize = true;
			this->btnConfirmBio->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnConfirmBio->Location = System::Drawing::Point(168, 49);
			this->btnConfirmBio->Margin = System::Windows::Forms::Padding(5, 2, 2, 2);
			this->btnConfirmBio->Name = L"btnConfirmBio";
			this->btnConfirmBio->Size = System::Drawing::Size(66, 27);
			this->btnConfirmBio->TabIndex = 6;
			this->btnConfirmBio->Text = L"Confirm";
			this->btnConfirmBio->UseVisualStyleBackColor = true;
			this->btnConfirmBio->Visible = false;
			this->btnConfirmBio->Click += gcnew System::EventHandler(this, &dashboard::btnConfirmBio_Click);
			// 
			// btnEditBio
			// 
			this->btnEditBio->AutoSize = true;
			this->btnEditBio->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEditBio->Location = System::Drawing::Point(124, 49);
			this->btnEditBio->Margin = System::Windows::Forms::Padding(5, 2, 2, 2);
			this->btnEditBio->Name = L"btnEditBio";
			this->btnEditBio->Size = System::Drawing::Size(42, 27);
			this->btnEditBio->TabIndex = 4;
			this->btnEditBio->Text = L"Edit";
			this->btnEditBio->UseVisualStyleBackColor = true;
			this->btnEditBio->Click += gcnew System::EventHandler(this, &dashboard::btnEditBio_Click);
			// 
			// lbUserBio
			// 
			this->lbUserBio->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbUserBio->AutoSize = true;
			this->lbUserBio->BackColor = System::Drawing::SystemColors::Window;
			this->lbUserBio->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbUserBio->Location = System::Drawing::Point(5, 83);
			this->lbUserBio->Margin = System::Windows::Forms::Padding(2, 12, 2, 0);
			this->lbUserBio->Name = L"lbUserBio";
			this->lbUserBio->Size = System::Drawing::Size(40, 20);
			this->lbUserBio->TabIndex = 3;
			this->lbUserBio->Text = L"[Bio]";
			// 
			// lbBiography
			// 
			this->lbBiography->AutoSize = true;
			this->lbBiography->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbBiography->Location = System::Drawing::Point(5, 44);
			this->lbBiography->Margin = System::Windows::Forms::Padding(2, 12, 2, 0);
			this->lbBiography->Name = L"lbBiography";
			this->lbBiography->Size = System::Drawing::Size(119, 26);
			this->lbBiography->TabIndex = 2;
			this->lbBiography->Text = L"Biography";
			// 
			// lbUserName
			// 
			this->lbUserName->AutoSize = true;
			this->lbUserName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbUserName->Location = System::Drawing::Point(5, 5);
			this->lbUserName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbUserName->Name = L"lbUserName";
			this->lbUserName->Size = System::Drawing::Size(89, 26);
			this->lbUserName->TabIndex = 1;
			this->lbUserName->Text = L"[Name]";
			// 
			// tbEditBio
			// 
			this->tbEditBio->AcceptsReturn = true;
			this->tbEditBio->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbEditBio->Location = System::Drawing::Point(5, 83);
			this->tbEditBio->Margin = System::Windows::Forms::Padding(2, 2, 5, 5);
			this->tbEditBio->Name = L"tbEditBio";
			this->tbEditBio->Size = System::Drawing::Size(752, 23);
			this->tbEditBio->TabIndex = 5;
			this->tbEditBio->Text = L"[Bio]";
			this->tbEditBio->Visible = false;
			// 
			// pnlSCourses
			// 
			this->pnlSCourses->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pnlSCourses->Controls->Add(this->cbShowCourses);
			this->pnlSCourses->Controls->Add(this->drpbxView);
			this->pnlSCourses->Controls->Add(this->dataCourses);
			this->pnlSCourses->Controls->Add(this->lbCourses);
			this->pnlSCourses->Controls->Add(this->dataGrades);
			this->pnlSCourses->Controls->Add(this->dataAttendance);
			this->pnlSCourses->Location = System::Drawing::Point(170, 5);
			this->pnlSCourses->Margin = System::Windows::Forms::Padding(2, 2, 5, 5);
			this->pnlSCourses->Name = L"pnlSCourses";
			this->pnlSCourses->Size = System::Drawing::Size(1410, 950);
			this->pnlSCourses->TabIndex = 7;
			this->pnlSCourses->Visible = false;
			// 
			// cbShowCourses
			// 
			this->cbShowCourses->AutoSize = true;
			this->cbShowCourses->Location = System::Drawing::Point(1006, 44);
			this->cbShowCourses->Margin = System::Windows::Forms::Padding(2);
			this->cbShowCourses->Name = L"cbShowCourses";
			this->cbShowCourses->Size = System::Drawing::Size(108, 17);
			this->cbShowCourses->TabIndex = 3;
			this->cbShowCourses->Text = L"Show All Courses";
			this->cbShowCourses->UseVisualStyleBackColor = true;
			this->cbShowCourses->CheckedChanged += gcnew System::EventHandler(this, &dashboard::cbShowCourses_CheckedChanged);
			// 
			// drpbxView
			// 
			this->drpbxView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->drpbxView->FormattingEnabled = true;
			this->drpbxView->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"None", L"Grades", L"Attendance" });
			this->drpbxView->Location = System::Drawing::Point(1300, 44);
			this->drpbxView->Margin = System::Windows::Forms::Padding(2);
			this->drpbxView->Name = L"drpbxView";
			this->drpbxView->Size = System::Drawing::Size(72, 21);
			this->drpbxView->TabIndex = 2;
			this->drpbxView->Text = L"View";
			this->drpbxView->SelectedIndexChanged += gcnew System::EventHandler(this, &dashboard::drpbxView_SelectedIndexChanged);
			// 
			// dataCourses
			// 
			this->dataCourses->AllowUserToAddRows = false;
			this->dataCourses->AllowUserToDeleteRows = false;
			this->dataCourses->AllowUserToResizeColumns = false;
			this->dataCourses->AllowUserToResizeRows = false;
			this->dataCourses->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataCourses->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataCourses->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataCourses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataCourses->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->clmCourseID,
					this->clmCourse
			});
			this->dataCourses->Location = System::Drawing::Point(5, 44);
			this->dataCourses->Margin = System::Windows::Forms::Padding(2, 12, 2, 2);
			this->dataCourses->MultiSelect = false;
			this->dataCourses->Name = L"dataCourses";
			this->dataCourses->ReadOnly = true;
			this->dataCourses->RowHeadersWidth = 82;
			this->dataCourses->RowTemplate->Height = 33;
			this->dataCourses->Size = System::Drawing::Size(950, 353);
			this->dataCourses->TabIndex = 1;
			this->dataCourses->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &dashboard::dataCourses_CellContentClick);
			// 
			// clmCourseID
			// 
			this->clmCourseID->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->clmCourseID->HeaderText = L"Course ID";
			this->clmCourseID->MinimumWidth = 10;
			this->clmCourseID->Name = L"clmCourseID";
			this->clmCourseID->ReadOnly = true;
			this->clmCourseID->Width = 79;
			// 
			// clmCourse
			// 
			this->clmCourse->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->clmCourse->HeaderText = L"Course";
			this->clmCourse->MinimumWidth = 10;
			this->clmCourse->Name = L"clmCourse";
			this->clmCourse->ReadOnly = true;
			this->clmCourse->Width = 65;
			// 
			// lbCourses
			// 
			this->lbCourses->AutoSize = true;
			this->lbCourses->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbCourses->Location = System::Drawing::Point(5, 5);
			this->lbCourses->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbCourses->Name = L"lbCourses";
			this->lbCourses->Size = System::Drawing::Size(100, 26);
			this->lbCourses->TabIndex = 0;
			this->lbCourses->Text = L"Courses";
			// 
			// dataGrades
			// 
			this->dataGrades->AllowUserToAddRows = false;
			this->dataGrades->AllowUserToDeleteRows = false;
			this->dataGrades->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGrades->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGrades->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->clmAssignment,
					this->clmPoints, this->clmTotal, this->clmPercentage
			});
			this->dataGrades->Location = System::Drawing::Point(5, 400);
			this->dataGrades->Margin = System::Windows::Forms::Padding(2);
			this->dataGrades->Name = L"dataGrades";
			this->dataGrades->ReadOnly = true;
			this->dataGrades->RowHeadersWidth = 82;
			this->dataGrades->RowTemplate->Height = 33;
			this->dataGrades->Size = System::Drawing::Size(1400, 545);
			this->dataGrades->TabIndex = 3;
			this->dataGrades->Visible = false;
			// 
			// clmAssignment
			// 
			this->clmAssignment->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->clmAssignment->HeaderText = L"Assignment";
			this->clmAssignment->MinimumWidth = 10;
			this->clmAssignment->Name = L"clmAssignment";
			this->clmAssignment->ReadOnly = true;
			this->clmAssignment->Width = 86;
			// 
			// clmPoints
			// 
			this->clmPoints->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->clmPoints->HeaderText = L"Points";
			this->clmPoints->MinimumWidth = 10;
			this->clmPoints->Name = L"clmPoints";
			this->clmPoints->ReadOnly = true;
			this->clmPoints->Width = 61;
			// 
			// clmTotal
			// 
			this->clmTotal->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->clmTotal->HeaderText = L"Total";
			this->clmTotal->MinimumWidth = 10;
			this->clmTotal->Name = L"clmTotal";
			this->clmTotal->ReadOnly = true;
			this->clmTotal->Width = 56;
			// 
			// clmPercentage
			// 
			this->clmPercentage->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->clmPercentage->HeaderText = L"Percentage";
			this->clmPercentage->MinimumWidth = 10;
			this->clmPercentage->Name = L"clmPercentage";
			this->clmPercentage->ReadOnly = true;
			this->clmPercentage->Width = 87;
			// 
			// dataAttendance
			// 
			this->dataAttendance->AllowUserToAddRows = false;
			this->dataAttendance->AllowUserToDeleteRows = false;
			this->dataAttendance->AllowUserToResizeColumns = false;
			this->dataAttendance->AllowUserToResizeRows = false;
			this->dataAttendance->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataAttendance->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataAttendance->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataAttendance->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataAttendance->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2
			});
			this->dataAttendance->Location = System::Drawing::Point(5, 400);
			this->dataAttendance->Margin = System::Windows::Forms::Padding(2, 12, 2, 2);
			this->dataAttendance->MultiSelect = false;
			this->dataAttendance->Name = L"dataAttendance";
			this->dataAttendance->ReadOnly = true;
			this->dataAttendance->RowHeadersWidth = 82;
			this->dataAttendance->RowTemplate->Height = 33;
			this->dataAttendance->Size = System::Drawing::Size(1400, 545);
			this->dataAttendance->TabIndex = 4;
			this->dataAttendance->Visible = false;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->dataGridViewTextBoxColumn1->HeaderText = L"Lecture";
			this->dataGridViewTextBoxColumn1->MinimumWidth = 10;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			this->dataGridViewTextBoxColumn1->Width = 68;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->dataGridViewTextBoxColumn2->HeaderText = L"Present";
			this->dataGridViewTextBoxColumn2->MinimumWidth = 10;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			this->dataGridViewTextBoxColumn2->Width = 68;
			// 
			// pnlReport
			// 
			this->pnlReport->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pnlReport->Controls->Add(this->btnCourseBackup);
			this->pnlReport->Controls->Add(this->tbCourseBackup);
			this->pnlReport->Controls->Add(this->lbPrompt);
			this->pnlReport->Location = System::Drawing::Point(170, 5);
			this->pnlReport->Margin = System::Windows::Forms::Padding(2);
			this->pnlReport->Name = L"pnlReport";
			this->pnlReport->Size = System::Drawing::Size(1410, 950);
			this->pnlReport->TabIndex = 5;
			this->pnlReport->Visible = false;
			// 
			// btnCourseBackup
			// 
			this->btnCourseBackup->Location = System::Drawing::Point(10, 60);
			this->btnCourseBackup->Margin = System::Windows::Forms::Padding(2, 5, 2, 2);
			this->btnCourseBackup->Name = L"btnCourseBackup";
			this->btnCourseBackup->Size = System::Drawing::Size(50, 23);
			this->btnCourseBackup->TabIndex = 2;
			this->btnCourseBackup->Text = L"Submit";
			this->btnCourseBackup->UseVisualStyleBackColor = true;
			// 
			// tbCourseBackup
			// 
			this->tbCourseBackup->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->tbCourseBackup->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tbCourseBackup->Location = System::Drawing::Point(10, 30);
			this->tbCourseBackup->Margin = System::Windows::Forms::Padding(2, 5, 2, 2);
			this->tbCourseBackup->Name = L"tbCourseBackup";
			this->tbCourseBackup->Size = System::Drawing::Size(112, 23);
			this->tbCourseBackup->TabIndex = 1;
			this->tbCourseBackup->Text = L"Course Name...";
			// 
			// lbPrompt
			// 
			this->lbPrompt->AutoSize = true;
			this->lbPrompt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbPrompt->Location = System::Drawing::Point(5, 5);
			this->lbPrompt->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbPrompt->Name = L"lbPrompt";
			this->lbPrompt->Size = System::Drawing::Size(327, 20);
			this->lbPrompt->TabIndex = 0;
			this->lbPrompt->Text = L"Which course would you like to backup\?";
			// 
			// pnlRegisterStudent
			// 
			this->pnlRegisterStudent->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pnlRegisterStudent->Controls->Add(this->btnRegisterSubmit);
			this->pnlRegisterStudent->Controls->Add(this->tbRegisterPswd);
			this->pnlRegisterStudent->Controls->Add(this->lbRegisterPswd);
			this->pnlRegisterStudent->Controls->Add(this->tbRegisterUsrnm);
			this->pnlRegisterStudent->Controls->Add(this->lbRegisterUsrnm);
			this->pnlRegisterStudent->Controls->Add(this->tbRegisterLN);
			this->pnlRegisterStudent->Controls->Add(this->lbRegisterLN);
			this->pnlRegisterStudent->Controls->Add(this->tbRegisterFN);
			this->pnlRegisterStudent->Controls->Add(this->lbRegisterFN);
			this->pnlRegisterStudent->Location = System::Drawing::Point(170, 5);
			this->pnlRegisterStudent->Margin = System::Windows::Forms::Padding(2);
			this->pnlRegisterStudent->Name = L"pnlRegisterStudent";
			this->pnlRegisterStudent->Size = System::Drawing::Size(1410, 950);
			this->pnlRegisterStudent->TabIndex = 24;
			this->pnlRegisterStudent->Visible = false;
			// 
			// btnRegisterSubmit
			// 
			this->btnRegisterSubmit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnRegisterSubmit->Location = System::Drawing::Point(5, 151);
			this->btnRegisterSubmit->Margin = System::Windows::Forms::Padding(2);
			this->btnRegisterSubmit->Name = L"btnRegisterSubmit";
			this->btnRegisterSubmit->Size = System::Drawing::Size(60, 26);
			this->btnRegisterSubmit->TabIndex = 8;
			this->btnRegisterSubmit->Text = L"Submit";
			this->btnRegisterSubmit->UseVisualStyleBackColor = true;
			this->btnRegisterSubmit->Click += gcnew System::EventHandler(this, &dashboard::btnRegisterSubmit_Click);
			// 
			// tbRegisterPswd
			// 
			this->tbRegisterPswd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->tbRegisterPswd->Location = System::Drawing::Point(109, 114);
			this->tbRegisterPswd->Margin = System::Windows::Forms::Padding(5, 5, 2, 2);
			this->tbRegisterPswd->Name = L"tbRegisterPswd";
			this->tbRegisterPswd->Size = System::Drawing::Size(162, 23);
			this->tbRegisterPswd->TabIndex = 7;
			// 
			// lbRegisterPswd
			// 
			this->lbRegisterPswd->AutoSize = true;
			this->lbRegisterPswd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbRegisterPswd->Location = System::Drawing::Point(5, 114);
			this->lbRegisterPswd->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbRegisterPswd->Name = L"lbRegisterPswd";
			this->lbRegisterPswd->Size = System::Drawing::Size(91, 20);
			this->lbRegisterPswd->TabIndex = 6;
			this->lbRegisterPswd->Text = L"Password:";
			// 
			// tbRegisterUsrnm
			// 
			this->tbRegisterUsrnm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->tbRegisterUsrnm->Location = System::Drawing::Point(109, 77);
			this->tbRegisterUsrnm->Margin = System::Windows::Forms::Padding(5, 5, 2, 2);
			this->tbRegisterUsrnm->Name = L"tbRegisterUsrnm";
			this->tbRegisterUsrnm->Size = System::Drawing::Size(162, 23);
			this->tbRegisterUsrnm->TabIndex = 5;
			// 
			// lbRegisterUsrnm
			// 
			this->lbRegisterUsrnm->AutoSize = true;
			this->lbRegisterUsrnm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbRegisterUsrnm->Location = System::Drawing::Point(5, 78);
			this->lbRegisterUsrnm->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbRegisterUsrnm->Name = L"lbRegisterUsrnm";
			this->lbRegisterUsrnm->Size = System::Drawing::Size(96, 20);
			this->lbRegisterUsrnm->TabIndex = 4;
			this->lbRegisterUsrnm->Text = L"Username:";
			// 
			// tbRegisterLN
			// 
			this->tbRegisterLN->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbRegisterLN->Location = System::Drawing::Point(109, 41);
			this->tbRegisterLN->Margin = System::Windows::Forms::Padding(5, 5, 2, 2);
			this->tbRegisterLN->Name = L"tbRegisterLN";
			this->tbRegisterLN->Size = System::Drawing::Size(162, 23);
			this->tbRegisterLN->TabIndex = 3;
			// 
			// lbRegisterLN
			// 
			this->lbRegisterLN->AutoSize = true;
			this->lbRegisterLN->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbRegisterLN->Location = System::Drawing::Point(5, 42);
			this->lbRegisterLN->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbRegisterLN->Name = L"lbRegisterLN";
			this->lbRegisterLN->Size = System::Drawing::Size(100, 20);
			this->lbRegisterLN->TabIndex = 2;
			this->lbRegisterLN->Text = L"Last Name:";
			// 
			// tbRegisterFN
			// 
			this->tbRegisterFN->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbRegisterFN->Location = System::Drawing::Point(109, 5);
			this->tbRegisterFN->Margin = System::Windows::Forms::Padding(5, 5, 2, 2);
			this->tbRegisterFN->Name = L"tbRegisterFN";
			this->tbRegisterFN->Size = System::Drawing::Size(162, 23);
			this->tbRegisterFN->TabIndex = 1;
			// 
			// lbRegisterFN
			// 
			this->lbRegisterFN->AutoSize = true;
			this->lbRegisterFN->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbRegisterFN->Location = System::Drawing::Point(5, 5);
			this->lbRegisterFN->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbRegisterFN->Name = L"lbRegisterFN";
			this->lbRegisterFN->Size = System::Drawing::Size(101, 20);
			this->lbRegisterFN->TabIndex = 0;
			this->lbRegisterFN->Text = L"First Name:";
			// 
			// dashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1584, 961);
			this->Controls->Add(this->pnlStudentSidebar);
			this->Controls->Add(this->btnLogout);
			this->Controls->Add(this->lbAppTitle);
			this->Controls->Add(this->pnlAdminSidebar);
			this->Controls->Add(this->pnlTeacherSidebar);
			this->Controls->Add(this->pnlDashboardProfile);
			this->Controls->Add(this->pnlSCourses);
			this->Controls->Add(this->pnlReport);
			this->Controls->Add(this->pnlRegisterStudent);
			this->MinimumSize = System::Drawing::Size(1600, 1000);
			this->Name = L"dashboard";
			this->Text = L"Dashboard";
			this->pnlStudentSidebar->ResumeLayout(false);
			this->pnlTeacherSidebar->ResumeLayout(false);
			this->pnlAdminSidebar->ResumeLayout(false);
			this->pnlDashboardProfile->ResumeLayout(false);
			this->pnlDashboardProfile->PerformLayout();
			this->pnlSCourses->ResumeLayout(false);
			this->pnlSCourses->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataCourses))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrades))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataAttendance))->EndInit();
			this->pnlReport->ResumeLayout(false);
			this->pnlReport->PerformLayout();
			this->pnlRegisterStudent->ResumeLayout(false);
			this->pnlRegisterStudent->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		// Student Sidebar
		private: System::Void btnSDashboard_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void btnSCourses_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void btnSGrades_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void btnSAttend_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void btnSReport_Click(System::Object^ sender, System::EventArgs^ e) {
		}

		// Teacher Sidebar
		private: System::Void btnTDashboard_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void btnTCourses_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void btnTSearch_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void btnTReport_Click(System::Object^ sender, System::EventArgs^ e) {
		}

		// Admin Sidebar
		private: System::Void btnADashboard_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void btnACourses_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void btnASearch_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void btnARegister_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void btnAReport_Click(System::Object^ sender, System::EventArgs^ e) {
		}

		// Logout
		private: System::Void btnLogout_Click(System::Object^ sender, System::EventArgs^ e) {
		}

		// Profile (main dashboard screen)
		private: System::Void btnEditBio_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void btnConfirmBio_Click(System::Object^ sender, System::EventArgs^ e) {
		}

		// Student Courses
		private: System::Void dataCourses_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		}
		private: System::Void cbShowCourses_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void drpbxView_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		}

		// Admin Register New Student
		private: System::Void btnRegisterSubmit_Click(System::Object^ sender, System::EventArgs^ e) {
		}
	};
}
