#pragma once
#include "Controller.h"
namespace CRLForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btn1Balance;
	private: System::Windows::Forms::Button^  btn3Writhdraw;
	private: System::Windows::Forms::Button^  btn2ReturnCard;
	private: System::Windows::Forms::Button^  btn4Deposit;
	protected:

	protected:



	private: System::Windows::Forms::TextBox^  textBox1;

	protected:
		Controller cont;
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
			this->btn1Balance = (gcnew System::Windows::Forms::Button());
			this->btn3Writhdraw = (gcnew System::Windows::Forms::Button());
			this->btn2ReturnCard = (gcnew System::Windows::Forms::Button());
			this->btn4Deposit = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// btn1Balance
			// 
			this->btn1Balance->Location = System::Drawing::Point(12, 21);
			this->btn1Balance->Name = L"btn1Balance";
			this->btn1Balance->Size = System::Drawing::Size(82, 30);
			this->btn1Balance->TabIndex = 0;
			this->btn1Balance->Text = L"Balance";
			this->btn1Balance->UseVisualStyleBackColor = true;
			this->btn1Balance->Click += gcnew System::EventHandler(this, &MyForm::btn1Balance_Click);
			// 
			// btn3Writhdraw
			// 
			this->btn3Writhdraw->Location = System::Drawing::Point(146, 21);
			this->btn3Writhdraw->Name = L"btn3Writhdraw";
			this->btn3Writhdraw->Size = System::Drawing::Size(75, 30);
			this->btn3Writhdraw->TabIndex = 1;
			this->btn3Writhdraw->Text = L"Withdraw";
			this->btn3Writhdraw->UseVisualStyleBackColor = true;
			this->btn3Writhdraw->Click += gcnew System::EventHandler(this, &MyForm::btn3Writhdraw_Click);
			// 
			// btn2ReturnCard
			// 
			this->btn2ReturnCard->Location = System::Drawing::Point(12, 71);
			this->btn2ReturnCard->Name = L"btn2ReturnCard";
			this->btn2ReturnCard->Size = System::Drawing::Size(82, 32);
			this->btn2ReturnCard->TabIndex = 2;
			this->btn2ReturnCard->Text = L"Return Card";
			this->btn2ReturnCard->UseVisualStyleBackColor = true;
			this->btn2ReturnCard->Click += gcnew System::EventHandler(this, &MyForm::btn2ReturnCard_Click);
			// 
			// btn4Deposit
			// 
			this->btn4Deposit->Location = System::Drawing::Point(146, 71);
			this->btn4Deposit->Name = L"btn4Deposit";
			this->btn4Deposit->Size = System::Drawing::Size(75, 32);
			this->btn4Deposit->TabIndex = 3;
			this->btn4Deposit->Text = L"Deposit";
			this->btn4Deposit->UseVisualStyleBackColor = true;
			this->btn4Deposit->Click += gcnew System::EventHandler(this, &MyForm::btn4Deposit_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(69, 121);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 4;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(251, 153);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->btn4Deposit);
			this->Controls->Add(this->btn2ReturnCard);
			this->Controls->Add(this->btn3Writhdraw);
			this->Controls->Add(this->btn1Balance);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}

private: System::Void btn1Balance_Click(System::Object^  sender, System::EventArgs^  e) {
	double balance = cont.getBalance();
	String^ stringVal;
	stringVal = System::Convert::ToString(balance);
	this->textBox1->Text = stringVal;
}
private: System::Void btn3Writhdraw_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ str = this->textBox1->Text;
	double  doubleVal = System::Convert::ToDouble(str);
	cont.debit(doubleVal);

}
private: System::Void btn2ReturnCard_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
private: System::Void btn4Deposit_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ str = this->textBox1->Text;
	double  doubleVal = System::Convert::ToDouble(str);
	cont.credit(doubleVal);

}
};
}
