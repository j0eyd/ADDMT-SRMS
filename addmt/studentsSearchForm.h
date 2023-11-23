#pragma once

namespace SRMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for studentsForm
	/// </summary>
	public ref class studentsForm : public System::Windows::Forms::Form
	{
	public:
		studentsForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~studentsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnLogout;
	protected:
	private: System::Windows::Forms::Button^ btnSettings;
	private: System::Windows::Forms::Button^ btnProfile;
	private: System::Windows::Forms::Button^ btnCourses;
	private: System::Windows::Forms::Button^ btnDashboard;
	private: System::Windows::Forms::Label^ lbAppTitle;
	private: System::Windows::Forms::TextBox^ tbStudentID;
	private: System::Windows::Forms::TextBox^ tbStudentName;
	private: System::Windows::Forms::TextBox^ tbCourseID;


	private: System::Windows::Forms::Button^ btnSearch;
	private: System::Windows::Forms::TableLayoutPanel^ tlpSearchBar;
	private: System::Windows::Forms::TableLayoutPanel^ tlpStudentList;



	private: System::Windows::Forms::Label^ lbCourseID;

	private: System::Windows::Forms::Label^ lbFirstName;
	private: System::Windows::Forms::Label^ lbCourse;

	private: System::Windows::Forms::Label^ lbStudentNameList;
	private: System::Windows::Forms::Label^ lbCourseIDList;
	private: System::Windows::Forms::Label^ lbCourseList;



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
			this->btnSettings = (gcnew System::Windows::Forms::Button());
			this->btnProfile = (gcnew System::Windows::Forms::Button());
			this->btnCourses = (gcnew System::Windows::Forms::Button());
			this->btnDashboard = (gcnew System::Windows::Forms::Button());
			this->lbAppTitle = (gcnew System::Windows::Forms::Label());
			this->tbStudentID = (gcnew System::Windows::Forms::TextBox());
			this->tbStudentName = (gcnew System::Windows::Forms::TextBox());
			this->tbCourseID = (gcnew System::Windows::Forms::TextBox());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->tlpSearchBar = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tlpStudentList = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->lbCourseList = (gcnew System::Windows::Forms::Label());
			this->lbCourseID = (gcnew System::Windows::Forms::Label());
			this->lbCourseIDList = (gcnew System::Windows::Forms::Label());
			this->lbFirstName = (gcnew System::Windows::Forms::Label());
			this->lbStudentNameList = (gcnew System::Windows::Forms::Label());
			this->lbCourse = (gcnew System::Windows::Forms::Label());
			this->tlpSearchBar->SuspendLayout();
			this->tlpStudentList->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnLogout
			// 
			this->btnLogout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btnLogout->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLogout->Location = System::Drawing::Point(5, 596);
			this->btnLogout->Name = L"btnLogout";
			this->btnLogout->Size = System::Drawing::Size(100, 40);
			this->btnLogout->TabIndex = 25;
			this->btnLogout->Text = L"Logout";
			this->btnLogout->UseVisualStyleBackColor = true;
			// 
			// btnSettings
			// 
			this->btnSettings->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSettings->Location = System::Drawing::Point(5, 245);
			this->btnSettings->Name = L"btnSettings";
			this->btnSettings->Size = System::Drawing::Size(100, 40);
			this->btnSettings->TabIndex = 24;
			this->btnSettings->Text = L"Settings";
			this->btnSettings->UseVisualStyleBackColor = true;
			// 
			// btnProfile
			// 
			this->btnProfile->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnProfile->Location = System::Drawing::Point(5, 200);
			this->btnProfile->Name = L"btnProfile";
			this->btnProfile->Size = System::Drawing::Size(100, 40);
			this->btnProfile->TabIndex = 23;
			this->btnProfile->Text = L"Profile";
			this->btnProfile->UseVisualStyleBackColor = true;
			// 
			// btnCourses
			// 
			this->btnCourses->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCourses->Location = System::Drawing::Point(5, 155);
			this->btnCourses->Name = L"btnCourses";
			this->btnCourses->Size = System::Drawing::Size(100, 40);
			this->btnCourses->TabIndex = 22;
			this->btnCourses->Text = L"Courses";
			this->btnCourses->UseVisualStyleBackColor = true;
			// 
			// btnDashboard
			// 
			this->btnDashboard->FlatAppearance->BorderSize = 0;
			this->btnDashboard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDashboard->Location = System::Drawing::Point(5, 110);
			this->btnDashboard->Name = L"btnDashboard";
			this->btnDashboard->Size = System::Drawing::Size(100, 40);
			this->btnDashboard->TabIndex = 21;
			this->btnDashboard->Text = L"Dashboard";
			this->btnDashboard->UseVisualStyleBackColor = true;
			this->btnDashboard->Click += gcnew System::EventHandler(this, &studentsForm::btnDashboard_Click);
			// 
			// lbAppTitle
			// 
			this->lbAppTitle->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbAppTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbAppTitle->Location = System::Drawing::Point(5, 5);
			this->lbAppTitle->Margin = System::Windows::Forms::Padding(0, 0, 3, 0);
			this->lbAppTitle->Name = L"lbAppTitle";
			this->lbAppTitle->Size = System::Drawing::Size(100, 100);
			this->lbAppTitle->TabIndex = 20;
			this->lbAppTitle->Text = L"SRMS";
			this->lbAppTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tbStudentID
			// 
			this->tbStudentID->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbStudentID->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tbStudentID->Location = System::Drawing::Point(3, 3);
			this->tbStudentID->Name = L"tbStudentID";
			this->tbStudentID->Size = System::Drawing::Size(240, 20);
			this->tbStudentID->TabIndex = 26;
			this->tbStudentID->Text = L"Student ID";
			// 
			// tbStudentName
			// 
			this->tbStudentName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbStudentName->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tbStudentName->Location = System::Drawing::Point(249, 3);
			this->tbStudentName->Name = L"tbStudentName";
			this->tbStudentName->Size = System::Drawing::Size(240, 20);
			this->tbStudentName->TabIndex = 27;
			this->tbStudentName->Text = L"Student Name";
			// 
			// tbCourseID
			// 
			this->tbCourseID->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbCourseID->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tbCourseID->Location = System::Drawing::Point(495, 3);
			this->tbCourseID->Name = L"tbCourseID";
			this->tbCourseID->Size = System::Drawing::Size(242, 20);
			this->tbCourseID->TabIndex = 28;
			this->tbCourseID->Text = L"Course ID";
			// 
			// btnSearch
			// 
			this->btnSearch->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnSearch->Location = System::Drawing::Point(860, 15);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(75, 20);
			this->btnSearch->TabIndex = 30;
			this->btnSearch->Text = L"Search";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &studentsForm::btnSearch_Click);
			// 
			// tlpSearchBar
			// 
			this->tlpSearchBar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tlpSearchBar->ColumnCount = 3;
			this->tlpSearchBar->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tlpSearchBar->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tlpSearchBar->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tlpSearchBar->Controls->Add(this->tbStudentID, 0, 0);
			this->tlpSearchBar->Controls->Add(this->tbCourseID, 2, 0);
			this->tlpSearchBar->Controls->Add(this->tbStudentName, 1, 0);
			this->tlpSearchBar->Location = System::Drawing::Point(112, 12);
			this->tlpSearchBar->Name = L"tlpSearchBar";
			this->tlpSearchBar->RowCount = 1;
			this->tlpSearchBar->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tlpSearchBar->Size = System::Drawing::Size(740, 28);
			this->tlpSearchBar->TabIndex = 31;
			this->tlpSearchBar->Visible = false;
			// 
			// tlpStudentList
			// 
			this->tlpStudentList->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tlpStudentList->ColumnCount = 3;
			this->tlpStudentList->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				30)));
			this->tlpStudentList->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				30)));
			this->tlpStudentList->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				40)));
			this->tlpStudentList->Controls->Add(this->lbCourseList, 2, 1);
			this->tlpStudentList->Controls->Add(this->lbCourseID, 1, 0);
			this->tlpStudentList->Controls->Add(this->lbCourseIDList, 1, 1);
			this->tlpStudentList->Controls->Add(this->lbFirstName, 0, 0);
			this->tlpStudentList->Controls->Add(this->lbStudentNameList, 0, 1);
			this->tlpStudentList->Controls->Add(this->lbCourse, 2, 0);
			this->tlpStudentList->Location = System::Drawing::Point(112, 47);
			this->tlpStudentList->Name = L"tlpStudentList";
			this->tlpStudentList->RowCount = 2;
			this->tlpStudentList->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 32)));
			this->tlpStudentList->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tlpStudentList->Size = System::Drawing::Size(823, 589);
			this->tlpStudentList->TabIndex = 32;
			this->tlpStudentList->Visible = false;
			// 
			// lbCourseList
			// 
			this->lbCourseList->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbCourseList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbCourseList->Location = System::Drawing::Point(495, 44);
			this->lbCourseList->Margin = System::Windows::Forms::Padding(3, 12, 3, 0);
			this->lbCourseList->Name = L"lbCourseList";
			this->lbCourseList->Size = System::Drawing::Size(325, 545);
			this->lbCourseList->TabIndex = 35;
			this->lbCourseList->Text = L"[Course]";
			// 
			// lbCourseID
			// 
			this->lbCourseID->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbCourseID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbCourseID->Location = System::Drawing::Point(249, 0);
			this->lbCourseID->Name = L"lbCourseID";
			this->lbCourseID->Size = System::Drawing::Size(240, 32);
			this->lbCourseID->TabIndex = 33;
			this->lbCourseID->Text = L"Course ID";
			this->lbCourseID->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lbCourseIDList
			// 
			this->lbCourseIDList->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbCourseIDList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbCourseIDList->Location = System::Drawing::Point(249, 44);
			this->lbCourseIDList->Margin = System::Windows::Forms::Padding(3, 12, 3, 0);
			this->lbCourseIDList->Name = L"lbCourseIDList";
			this->lbCourseIDList->Size = System::Drawing::Size(240, 545);
			this->lbCourseIDList->TabIndex = 34;
			this->lbCourseIDList->Text = L"[Course ID]";
			// 
			// lbFirstName
			// 
			this->lbFirstName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbFirstName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbFirstName->Location = System::Drawing::Point(3, 0);
			this->lbFirstName->Name = L"lbFirstName";
			this->lbFirstName->Size = System::Drawing::Size(240, 32);
			this->lbFirstName->TabIndex = 0;
			this->lbFirstName->Text = L"Name";
			this->lbFirstName->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lbStudentNameList
			// 
			this->lbStudentNameList->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbStudentNameList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbStudentNameList->Location = System::Drawing::Point(3, 44);
			this->lbStudentNameList->Margin = System::Windows::Forms::Padding(3, 12, 3, 0);
			this->lbStudentNameList->Name = L"lbStudentNameList";
			this->lbStudentNameList->Size = System::Drawing::Size(240, 545);
			this->lbStudentNameList->TabIndex = 33;
			this->lbStudentNameList->Text = L"[Name]";
			// 
			// lbCourse
			// 
			this->lbCourse->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbCourse->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbCourse->Location = System::Drawing::Point(495, 0);
			this->lbCourse->Name = L"lbCourse";
			this->lbCourse->Size = System::Drawing::Size(325, 32);
			this->lbCourse->TabIndex = 33;
			this->lbCourse->Text = L"Course";
			this->lbCourse->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// studentsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 641);
			this->Controls->Add(this->tlpStudentList);
			this->Controls->Add(this->tlpSearchBar);
			this->Controls->Add(this->btnSearch);
			this->Controls->Add(this->btnLogout);
			this->Controls->Add(this->btnSettings);
			this->Controls->Add(this->btnProfile);
			this->Controls->Add(this->btnCourses);
			this->Controls->Add(this->btnDashboard);
			this->Controls->Add(this->lbAppTitle);
			this->MinimumSize = System::Drawing::Size(1000, 680);
			this->Name = L"studentsForm";
			this->Text = L"Students";
			this->tlpSearchBar->ResumeLayout(false);
			this->tlpSearchBar->PerformLayout();
			this->tlpStudentList->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnDashboard_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
		// TODO: add functionality to search database for students based on tbStudentID->Text || tbStudentName->Text || tbCourseID->Text if they exist
	}
	};
}
