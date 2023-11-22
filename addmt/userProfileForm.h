#pragma once

namespace SRMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for userProfileForm
	/// </summary>
	public ref class userProfileForm : public System::Windows::Forms::Form
	{
	public:
		userProfileForm(void)
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
		~userProfileForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pbPFP;
	private: System::Windows::Forms::Label^ lbUserName;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lbBiography;
	private: System::Windows::Forms::Label^ lbUserBio;

	private: System::Windows::Forms::Label^ lbPersonalInfo;
	private: System::Windows::Forms::Label^ lbUserInfo;
	private: System::Windows::Forms::Label^ lbAppTitle;
	private: System::Windows::Forms::Button^ btnDashboard;
	private: System::Windows::Forms::Button^ btnCourses;
	private: System::Windows::Forms::Button^ btnProfile;
	private: System::Windows::Forms::Button^ btnSettings;
	private: System::Windows::Forms::Button^ btnLogout;









	protected:


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
			this->pbPFP = (gcnew System::Windows::Forms::PictureBox());
			this->lbUserName = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lbBiography = (gcnew System::Windows::Forms::Label());
			this->lbUserBio = (gcnew System::Windows::Forms::Label());
			this->lbPersonalInfo = (gcnew System::Windows::Forms::Label());
			this->lbUserInfo = (gcnew System::Windows::Forms::Label());
			this->lbAppTitle = (gcnew System::Windows::Forms::Label());
			this->btnDashboard = (gcnew System::Windows::Forms::Button());
			this->btnCourses = (gcnew System::Windows::Forms::Button());
			this->btnProfile = (gcnew System::Windows::Forms::Button());
			this->btnSettings = (gcnew System::Windows::Forms::Button());
			this->btnLogout = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPFP))->BeginInit();
			this->SuspendLayout();
			// 
			// pbPFP
			// 
			this->pbPFP->Location = System::Drawing::Point(114, 12);
			this->pbPFP->Name = L"pbPFP";
			this->pbPFP->Size = System::Drawing::Size(110, 110);
			this->pbPFP->TabIndex = 0;
			this->pbPFP->TabStop = false;
			// 
			// lbUserName
			// 
			this->lbUserName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbUserName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbUserName->Location = System::Drawing::Point(233, 12);
			this->lbUserName->Name = L"lbUserName";
			this->lbUserName->Size = System::Drawing::Size(739, 25);
			this->lbUserName->TabIndex = 1;
			this->lbUserName->Text = L"[Name]";
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 23);
			this->label1->TabIndex = 4;
			// 
			// lbBiography
			// 
			this->lbBiography->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbBiography->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbBiography->Location = System::Drawing::Point(110, 133);
			this->lbBiography->Margin = System::Windows::Forms::Padding(3, 12, 3, 0);
			this->lbBiography->Name = L"lbBiography";
			this->lbBiography->Size = System::Drawing::Size(858, 23);
			this->lbBiography->TabIndex = 3;
			this->lbBiography->Text = L"Biography";
			// 
			// lbUserBio
			// 
			this->lbUserBio->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbUserBio->BackColor = System::Drawing::SystemColors::Window;
			this->lbUserBio->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lbUserBio->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbUserBio->Location = System::Drawing::Point(114, 164);
			this->lbUserBio->Margin = System::Windows::Forms::Padding(3, 8, 3, 0);
			this->lbUserBio->Name = L"lbUserBio";
			this->lbUserBio->Size = System::Drawing::Size(854, 150);
			this->lbUserBio->TabIndex = 5;
			// 
			// lbPersonalInfo
			// 
			this->lbPersonalInfo->AutoSize = true;
			this->lbPersonalInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbPersonalInfo->Location = System::Drawing::Point(110, 394);
			this->lbPersonalInfo->Margin = System::Windows::Forms::Padding(3, 80, 3, 0);
			this->lbPersonalInfo->Name = L"lbPersonalInfo";
			this->lbPersonalInfo->Size = System::Drawing::Size(201, 24);
			this->lbPersonalInfo->TabIndex = 6;
			this->lbPersonalInfo->Text = L"Personal Information";
			this->lbPersonalInfo->Click += gcnew System::EventHandler(this, &userProfileForm::lbPersonalInfo_Click);
			// 
			// lbUserInfo
			// 
			this->lbUserInfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbUserInfo->BackColor = System::Drawing::SystemColors::Window;
			this->lbUserInfo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lbUserInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbUserInfo->Location = System::Drawing::Point(114, 426);
			this->lbUserInfo->Margin = System::Windows::Forms::Padding(3, 8, 3, 0);
			this->lbUserInfo->Name = L"lbUserInfo";
			this->lbUserInfo->Size = System::Drawing::Size(854, 150);
			this->lbUserInfo->TabIndex = 7;
			this->lbUserInfo->Click += gcnew System::EventHandler(this, &userProfileForm::lbUserInfo_Click);
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
			this->lbAppTitle->TabIndex = 8;
			this->lbAppTitle->Text = L"SRMS";
			this->lbAppTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btnDashboard
			// 
			this->btnDashboard->FlatAppearance->BorderSize = 0;
			this->btnDashboard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDashboard->Location = System::Drawing::Point(5, 110);
			this->btnDashboard->Name = L"btnDashboard";
			this->btnDashboard->Size = System::Drawing::Size(100, 40);
			this->btnDashboard->TabIndex = 9;
			this->btnDashboard->Text = L"Dashboard";
			this->btnDashboard->UseVisualStyleBackColor = true;
			this->btnDashboard->Click += gcnew System::EventHandler(this, &userProfileForm::btnDashboard_Click);
			// 
			// btnCourses
			// 
			this->btnCourses->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCourses->Location = System::Drawing::Point(5, 155);
			this->btnCourses->Name = L"btnCourses";
			this->btnCourses->Size = System::Drawing::Size(100, 40);
			this->btnCourses->TabIndex = 10;
			this->btnCourses->Text = L"Courses";
			this->btnCourses->UseVisualStyleBackColor = true;
			this->btnCourses->Click += gcnew System::EventHandler(this, &userProfileForm::btnCourses_Click);
			// 
			// btnProfile
			// 
			this->btnProfile->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnProfile->Location = System::Drawing::Point(5, 200);
			this->btnProfile->Name = L"btnProfile";
			this->btnProfile->Size = System::Drawing::Size(100, 40);
			this->btnProfile->TabIndex = 11;
			this->btnProfile->Text = L"Profile";
			this->btnProfile->UseVisualStyleBackColor = true;
			this->btnProfile->Click += gcnew System::EventHandler(this, &userProfileForm::btnProfile_Click);
			// 
			// btnSettings
			// 
			this->btnSettings->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSettings->Location = System::Drawing::Point(5, 245);
			this->btnSettings->Name = L"btnSettings";
			this->btnSettings->Size = System::Drawing::Size(100, 40);
			this->btnSettings->TabIndex = 12;
			this->btnSettings->Text = L"Settings";
			this->btnSettings->UseVisualStyleBackColor = true;
			this->btnSettings->Click += gcnew System::EventHandler(this, &userProfileForm::btnSettings_Click);
			// 
			// btnLogout
			// 
			this->btnLogout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btnLogout->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLogout->Location = System::Drawing::Point(5, 596);
			this->btnLogout->Name = L"btnLogout";
			this->btnLogout->Size = System::Drawing::Size(100, 40);
			this->btnLogout->TabIndex = 13;
			this->btnLogout->Text = L"Logout";
			this->btnLogout->UseVisualStyleBackColor = true;
			this->btnLogout->Click += gcnew System::EventHandler(this, &userProfileForm::btnLogout_Click);
			// 
			// userProfileForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 641);
			this->Controls->Add(this->btnLogout);
			this->Controls->Add(this->btnSettings);
			this->Controls->Add(this->btnProfile);
			this->Controls->Add(this->btnCourses);
			this->Controls->Add(this->btnDashboard);
			this->Controls->Add(this->lbAppTitle);
			this->Controls->Add(this->lbUserInfo);
			this->Controls->Add(this->lbPersonalInfo);
			this->Controls->Add(this->lbUserBio);
			this->Controls->Add(this->lbBiography);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lbUserName);
			this->Controls->Add(this->pbPFP);
			this->MinimumSize = System::Drawing::Size(1000, 680);
			this->Name = L"userProfileForm";
			this->Text = L"Profile";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPFP))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
private: System::Void btnDashboard_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnCourses_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnProfile_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnSettings_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnLogout_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
