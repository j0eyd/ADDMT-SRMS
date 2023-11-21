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
			//
			//TODO: Add the constructor code here
			//

			lbUserInfo->Text = "Username: " + user->username;
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
	private: System::Windows::Forms::Label^ lbTitle;
	protected:

	private: System::Windows::Forms::Label^ lbUserInfo;
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
			this->lbTitle = (gcnew System::Windows::Forms::Label());
			this->lbUserInfo = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lbTitle
			// 
			this->lbTitle->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbTitle->Location = System::Drawing::Point(12, 9);
			this->lbTitle->Name = L"lbTitle";
			this->lbTitle->Size = System::Drawing::Size(876, 34);
			this->lbTitle->TabIndex = 0;
			this->lbTitle->Text = L"Dashboard";
			this->lbTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbUserInfo
			// 
			this->lbUserInfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbUserInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbUserInfo->Location = System::Drawing::Point(13, 76);
			this->lbUserInfo->Name = L"lbUserInfo";
			this->lbUserInfo->Size = System::Drawing::Size(875, 23);
			this->lbUserInfo->TabIndex = 1;
			this->lbUserInfo->Text = L"label2";
			// 
			// dashboardForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(900, 666);
			this->Controls->Add(this->lbUserInfo);
			this->Controls->Add(this->lbTitle);
			this->Name = L"dashboardForm";
			this->Text = L"dashboardForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
