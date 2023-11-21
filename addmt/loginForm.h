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
			this->SuspendLayout();
			// 
			// labelTitle
			// 
			this->labelTitle->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitle->Location = System::Drawing::Point(12, 9);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(408, 77);
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
			this->tbUsername->Location = System::Drawing::Point(172, 122);
			this->tbUsername->Name = L"tbUsername";
			this->tbUsername->Size = System::Drawing::Size(248, 26);
			this->tbUsername->TabIndex = 1;
			// 
			// labelUsername
			// 
			this->labelUsername->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->labelUsername->AutoSize = true;
			this->labelUsername->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelUsername->Location = System::Drawing::Point(14, 124);
			this->labelUsername->Name = L"labelUsername";
			this->labelUsername->Size = System::Drawing::Size(105, 24);
			this->labelUsername->TabIndex = 2;
			this->labelUsername->Text = L"Username";
			// 
			// tbPassword
			// 
			this->tbPassword->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPassword->Location = System::Drawing::Point(172, 194);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->PasswordChar = '*';
			this->tbPassword->Size = System::Drawing::Size(248, 26);
			this->tbPassword->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(407, 504);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(0, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Submit";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// labelPassword
			// 
			this->labelPassword->AutoSize = true;
			this->labelPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPassword->Location = System::Drawing::Point(14, 196);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(100, 24);
			this->labelPassword->TabIndex = 5;
			this->labelPassword->Text = L"Password";
			// 
			// btnSubmit
			// 
			this->btnSubmit->Location = System::Drawing::Point(181, 249);
			this->btnSubmit->Name = L"btnSubmit";
			this->btnSubmit->Size = System::Drawing::Size(75, 23);
			this->btnSubmit->TabIndex = 6;
			this->btnSubmit->Text = L"Submit";
			this->btnSubmit->UseVisualStyleBackColor = true;
			this->btnSubmit->Click += gcnew System::EventHandler(this, &loginForm::btnSubmit_Click);
			// 
			// loginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(432, 306);
			this->Controls->Add(this->btnSubmit);
			this->Controls->Add(this->labelPassword);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->labelUsername);
			this->Controls->Add(this->tbUsername);
			this->Controls->Add(this->labelTitle);
			this->Name = L"loginForm";
			this->Text = L"Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: User^ user = nullptr;

	private: System::Void btnSubmit_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ username = this->tbUsername->Text;
		String^ password = this->tbPassword->Text;

		if (username->Length == 0 || password->Length == 0) {
			MessageBox::Show("Please enter a username and password", "Username or Password Empty", MessageBoxButtons::OK);
		}

		// TODO: Connect to and query database for correct username and password

		if (username == "craeton") {
			user = gcnew User;
			user->username = "craeton";
			this->Close();
		}

	}
	};
}
