#pragma once

namespace SRMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for coursesForm
	/// </summary>
	public ref class coursesForm : public System::Windows::Forms::Form
	{
	public:
		coursesForm(void)
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
		~coursesForm()
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
	private: System::Windows::Forms::TableLayoutPanel^ tlpLabels;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lbCourseID;
	private: System::Windows::Forms::Label^ lbCourseName;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

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
			this->tlpLabels = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lbCourseID = (gcnew System::Windows::Forms::Label());
			this->lbCourseName = (gcnew System::Windows::Forms::Label());
			this->tlpLabels->SuspendLayout();
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
			// tlpLabels
			// 
			this->tlpLabels->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tlpLabels->ColumnCount = 2;
			this->tlpLabels->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 22.29965F)));
			this->tlpLabels->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 77.70035F)));
			this->tlpLabels->Controls->Add(this->label1, 0, 0);
			this->tlpLabels->Controls->Add(this->label2, 1, 0);
			this->tlpLabels->Location = System::Drawing::Point(111, 12);
			this->tlpLabels->Name = L"tlpLabels";
			this->tlpLabels->RowCount = 1;
			this->tlpLabels->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tlpLabels->Size = System::Drawing::Size(861, 39);
			this->tlpLabels->TabIndex = 26;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Margin = System::Windows::Forms::Padding(0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(192, 39);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Course ID";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(192, 0);
			this->label2->Margin = System::Windows::Forms::Padding(0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(669, 39);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Course";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lbCourseID
			// 
			this->lbCourseID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbCourseID->Location = System::Drawing::Point(111, 66);
			this->lbCourseID->Margin = System::Windows::Forms::Padding(3, 12, 3, 0);
			this->lbCourseID->Name = L"lbCourseID";
			this->lbCourseID->Size = System::Drawing::Size(189, 566);
			this->lbCourseID->TabIndex = 27;
			this->lbCourseID->Text = L"[Course ID]";
			// 
			// lbCourseName
			// 
			this->lbCourseName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbCourseName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbCourseName->Location = System::Drawing::Point(310, 66);
			this->lbCourseName->Name = L"lbCourseName";
			this->lbCourseName->Size = System::Drawing::Size(662, 566);
			this->lbCourseName->TabIndex = 28;
			this->lbCourseName->Text = L"[Course Name]";
			// 
			// coursesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 641);
			this->Controls->Add(this->lbCourseName);
			this->Controls->Add(this->lbCourseID);
			this->Controls->Add(this->tlpLabels);
			this->Controls->Add(this->btnLogout);
			this->Controls->Add(this->btnSettings);
			this->Controls->Add(this->btnProfile);
			this->Controls->Add(this->btnCourses);
			this->Controls->Add(this->btnDashboard);
			this->Controls->Add(this->lbAppTitle);
			this->MinimumSize = System::Drawing::Size(1000, 680);
			this->Name = L"coursesForm";
			this->Text = L"Courses";
			this->tlpLabels->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
