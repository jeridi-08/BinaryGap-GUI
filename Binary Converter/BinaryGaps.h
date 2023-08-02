#pragma once
#include <cstdlib>
#include <string>

namespace BinaryConverter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// Implementation of the binary function to convert decimal to binary
	std::string binary(long double decimal_value) {
		std::string binary_value = "";
		int i = (int)log2(decimal_value);
		while (i >= 0) {
			long double x = decimal_value - (pow(2, i));
			if (x >= 0) {
				binary_value = binary_value + "1";
				decimal_value = x;
			}
			else {
				binary_value = binary_value + "0";
			}
			i = i - 1;
		}
		return binary_value;
	}
	int binary_length(std::string binary_value) {
		int biggest_gap = 0;
		int current_gap = 0;
		int i = 0;
		int number_of_ones = 0;
		while (i <= (binary_value.length())) {
			if ((binary_value[i]) == '0') {
				current_gap++;
			}
			else {
				if (biggest_gap < current_gap) {
					biggest_gap = current_gap;
				}
				current_gap = 0;
				number_of_ones++;
			}
			i++;
		}
		if (number_of_ones <= 2) {
			biggest_gap = 0;
		}
		return biggest_gap;
	}

	/// <summary>
	/// Summary for BinaryGaps
	/// </summary>
	public ref class BinaryGaps : public System::Windows::Forms::Form
	{
	public:
		BinaryGaps(void)
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
		~BinaryGaps()
		{
			if (components)
			{
				delete components;
			}
		}

	public: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(62, 167);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(760, 46);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"Type a number";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &BinaryGaps::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 23, System::Drawing::FontStyle::Bold));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label2->Location = System::Drawing::Point(48, 55);
			this->label2->Name = L"label2";
			this->label2->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->label2->Size = System::Drawing::Size(887, 84);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Decimal to binary converter";
			this->label2->Click += gcnew System::EventHandler(this, &BinaryGaps::label2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(722, 271);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(203, 72);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Convert";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &BinaryGaps::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::White;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button2->Location = System::Drawing::Point(62, 271);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(203, 72);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Quit";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label1->Location = System::Drawing::Point(56, 386);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 40);
			this->label1->TabIndex = 5;
			this->label1->Click += gcnew System::EventHandler(this, &BinaryGaps::label1_Click_1);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label3->Location = System::Drawing::Point(55, 443);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 40);
			this->label3->TabIndex = 6;
			// 
			// BinaryGaps
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(986, 542);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Name = L"BinaryGaps";
			this->Text = L"BinaryGaps";
			this->Load += gcnew System::EventHandler(this, &BinaryGaps::BinaryGaps_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		double decimal_value;
		decimal_value = System::Convert::ToDouble(textBox1->Text);
		std::string final_value = binary(decimal_value);
		int final_value_gap = binary_length(final_value);
		this->label1->Text = ("Binary value: "+gcnew System::String(final_value.c_str()));
		this->label3->Text = ("Binary gap: " + final_value_gap);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		exit(1);
	}
private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void BinaryGaps_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
