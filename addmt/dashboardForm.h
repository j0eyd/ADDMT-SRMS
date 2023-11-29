#pragma once
#include "User.h"

namespace SRMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for dashboardForm
	/// </summary>
	public ref class dashboardForm : public System::Windows::Forms::Form
	{
	public:
		dashboardForm(User^ user)
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
		~dashboardForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btnLogout;
	private: System::Windows::Forms::Button^ btnSettings;
	private: System::Windows::Forms::Button^ btnProfile;
	private: System::Windows::Forms::Button^ btnCourses;
	private: System::Windows::Forms::Button^ btnDashboard;
	private: System::Windows::Forms::Label^ lbAppTitle;

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
			this->btnLogout->TabIndex = 19;
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
			this->btnSettings->TabIndex = 18;
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
			this->btnProfile->TabIndex = 17;
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
			this->btnCourses->TabIndex = 16;
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
			this->btnDashboard->TabIndex = 15;
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
			this->lbAppTitle->TabIndex = 14;
			this->lbAppTitle->Text = L"SRMS";
			this->lbAppTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// dashboardForm
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
			this->MinimumSize = System::Drawing::Size(1000, 680);
			this->Name = L"dashboardForm";
			this->Text = L"Dashboard";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnLogout_Click(System::Object^ sender, System::EventArgs^ e) {

		// Create an instance of the NewForm
		// NewForm^ newForm = gcnew NewForm();
		// Show the NewForm
		// newForm->Show();
	}

	private: System::Void btnSettings_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create an instance of the NewForm
		// NewForm^ newForm = gcnew NewForm();
		// Show the NewForm
		// newForm->Show();
	}

	private: System::Void btnProfile_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create an instance of the NewForm
		// NewForm^ newForm = gcnew NewForm();
		// Show the NewForm
		// newForm->Show();
	}
	private: System::Void btnCourses_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create an instance of the NewForm
		// NewForm^ newForm = gcnew NewForm();
		// Show the NewForm
		// newForm->Show();
	}
	private: System::Void btnDashboard_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create an instance of the NewForm
		// NewForm^ newForm = gcnew NewForm();
		// Show the NewForm
		// newForm->Show();
	}
		// Begin functionality here
	};
}
