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
	/// Summary for loginForm
	/// </summary>
	public ref class loginForm : public System::Windows::Forms::Form
	{
	public:
		loginForm(void)
		{
			InitializeComponent();

			user = gcnew User;

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~loginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelTitle;
	protected:

	private: System::Windows::Forms::TextBox^ tbUsername;
	private: System::Windows::Forms::Label^ labelUsername;


	private: System::Windows::Forms::TextBox^ tbPassword;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ labelPassword;
	private: System::Windows::Forms::Button^ btnSubmit;
	private: System::Windows::Forms::TableLayoutPanel^ tlpLoginFormOptions;
	private: System::Windows::Forms::Label^ lbRegister;
	private: System::Windows::Forms::Label^ lbPassReset;




	protected:


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
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->tbUsername = (gcnew System::Windows::Forms::TextBox());
			this->labelUsername = (gcnew System::Windows::Forms::Label());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->labelPassword = (gcnew System::Windows::Forms::Label());
			this->btnSubmit = (gcnew System::Windows::Forms::Button());
			this->tlpLoginFormOptions = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->lbRegister = (gcnew System::Windows::Forms::Label());
			this->lbPassReset = (gcnew System::Windows::Forms::Label());
			this->tlpLoginFormOptions->SuspendLayout();
			this->SuspendLayout();
			// 
			// labelTitle
			// 
			this->labelTitle->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitle->Location = System::Drawing::Point(18, 14);
			this->labelTitle->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(630, 118);
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"SRMS Login";
			this->labelTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tbUsername
			// 
			this->tbUsername->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbUsername->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbUsername->Location = System::Drawing::Point(258, 188);
			this->tbUsername->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->tbUsername->Name = L"tbUsername";
			this->tbUsername->Size = System::Drawing::Size(388, 35);
			this->tbUsername->TabIndex = 1;
			this->tbUsername->TextChanged += gcnew System::EventHandler(this, &loginForm::tbUsername_TextChanged);
			// 
			// labelUsername
			// 
			this->labelUsername->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelUsername->AutoSize = true;
			this->labelUsername->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelUsername->Location = System::Drawing::Point(21, 191);
			this->labelUsername->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelUsername->Name = L"labelUsername";
			this->labelUsername->Size = System::Drawing::Size(158, 33);
			this->labelUsername->TabIndex = 2;
			this->labelUsername->Text = L"Username";
			// 
			// tbPassword
			// 
			this->tbPassword->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPassword->Location = System::Drawing::Point(258, 298);
			this->tbPassword->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->PasswordChar = '*';
			this->tbPassword->Size = System::Drawing::Size(388, 35);
			this->tbPassword->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(610, 775);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(18, 35);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Submit";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// labelPassword
			// 
			this->labelPassword->AutoSize = true;
			this->labelPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPassword->Location = System::Drawing::Point(21, 302);
			this->labelPassword->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(151, 33);
			this->labelPassword->TabIndex = 5;
			this->labelPassword->Text = L"Password";
			// 
			// btnSubmit
			// 
			this->btnSubmit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnSubmit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSubmit->Location = System::Drawing::Point(267, 385);
			this->btnSubmit->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnSubmit->Name = L"btnSubmit";
			this->btnSubmit->Size = System::Drawing::Size(112, 35);
			this->btnSubmit->TabIndex = 6;
			this->btnSubmit->Text = L"Submit";
			this->btnSubmit->UseVisualStyleBackColor = true;
			this->btnSubmit->Click += gcnew System::EventHandler(this, &loginForm::btnSubmit_Click);
			// 
			// tlpLoginFormOptions
			// 
			this->tlpLoginFormOptions->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tlpLoginFormOptions->ColumnCount = 2;
			this->tlpLoginFormOptions->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				49.48806F)));
			this->tlpLoginFormOptions->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50.51194F)));
			this->tlpLoginFormOptions->Controls->Add(this->lbRegister, 0, 0);
			this->tlpLoginFormOptions->Controls->Add(this->lbPassReset, 1, 0);
			this->tlpLoginFormOptions->Location = System::Drawing::Point(132, 451);
			this->tlpLoginFormOptions->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->tlpLoginFormOptions->Name = L"tlpLoginFormOptions";
			this->tlpLoginFormOptions->RowCount = 1;
			this->tlpLoginFormOptions->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tlpLoginFormOptions->Size = System::Drawing::Size(414, 48);
			this->tlpLoginFormOptions->TabIndex = 7;
			this->tlpLoginFormOptions->Visible = false;
			this->tlpLoginFormOptions->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &loginForm::tableLayoutPanel1_Paint);
			// 
			// lbRegister
			// 
			this->lbRegister->BackColor = System::Drawing::SystemColors::Window;
			this->lbRegister->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbRegister->Location = System::Drawing::Point(0, 0);
			this->lbRegister->Margin = System::Windows::Forms::Padding(0);
			this->lbRegister->Name = L"lbRegister";
			this->lbRegister->Size = System::Drawing::Size(204, 48);
			this->lbRegister->TabIndex = 0;
			this->lbRegister->Text = L"Register";
			this->lbRegister->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lbRegister->Click += gcnew System::EventHandler(this, &loginForm::label1_Click);
			// 
			// lbPassReset
			// 
			this->lbPassReset->BackColor = System::Drawing::SystemColors::Window;
			this->lbPassReset->Location = System::Drawing::Point(204, 0);
			this->lbPassReset->Margin = System::Windows::Forms::Padding(0);
			this->lbPassReset->Name = L"lbPassReset";
			this->lbPassReset->Size = System::Drawing::Size(210, 48);
			this->lbPassReset->TabIndex = 1;
			this->lbPassReset->Text = L"Forgot Password\?";
			this->lbPassReset->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lbPassReset->Click += gcnew System::EventHandler(this, &loginForm::lbPassReset_Click);
			// 
			// loginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(657, 514);
			this->Controls->Add(this->tlpLoginFormOptions);
			this->Controls->Add(this->btnSubmit);
			this->Controls->Add(this->labelPassword);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->labelUsername);
			this->Controls->Add(this->tbUsername);
			this->Controls->Add(this->labelTitle);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximumSize = System::Drawing::Size(679, 570);
			this->MinimumSize = System::Drawing::Size(679, 570);
			this->Name = L"loginForm";
			this->Text = L"Login";
			this->tlpLoginFormOptions->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: user = nullptr;

	private: System::Void btnSubmit_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ username = this->tbUsername->Text;
		String^ password = this->tbPassword->Text;

		if (username->Length == 0 || password->Length == 0) {
			MessageBox::Show("Please enter a username and password", "Username or Password Empty", MessageBoxButtons::OK);
		}

		// TODO: Connect to and query database for correct username and password
		int loginStatus = user->loginSearch(username, password);
		if (loginStatus == 0) {
			// no credentials found.
			MessageBox::Show("Login failed", "Login Failed", MessageBoxButtons::OK);
		}
		else if (loginStatus == 1) {
			// login username is correct, password is not.
			MessageBox::Show("Login failed: Password is Incorrect", "Login Failed", MessageBoxButtons::OK);
		}
		else if (loginStatus == 2) {
			// login success (username and password are present and correct)
			
			dashboardForm^ dashboard = gcnew dashboardForm(user);
			dashboard->Show();
			this->Close();
		}


		// if (username == "craeton") {
			// user = gcnew User;
			//user->username = "craeton";
			// this->Close();
		// }

	}
	private: System::Void lbRegister_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void lbPassReset_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void tbUsername_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
