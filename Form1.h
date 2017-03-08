#pragma once

namespace SlidingPanel {



  using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

    public ref class Form1 : public System::Windows::Forms::Form
    {
public:
		Form1(void)
		{
			InitializeComponent();
		}

	protected:

		~Form1()
		{
			if (components)
			{
				delete components;
			}
        }


	private: System::Windows::Forms::Button^  btnOpen;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  btnClose;

    private:

    #pragma region Windows Form Designer generated code
    void InitializeComponent(void)
		{
this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
this->btnOpen = (gcnew System::Windows::Forms::Button());
this->btnClose = (gcnew System::Windows::Forms::Button());
this->panel1 = (gcnew System::Windows::Forms::Panel());
this->panel1->SuspendLayout();
			this->SuspendLayout();


//btnOpen
            this->btnOpen->Location = System::Drawing::Point(30, 25);
			this->btnOpen->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnOpen->Name = L"btnOpen";
			this->btnOpen->Size = System::Drawing::Size(72, 24);
			this->btnOpen->TabIndex = 26;
			this->btnOpen->Text = L"Configure";
			this->btnOpen->UseVisualStyleBackColor = true;
			this->btnOpen->Click += gcnew System::EventHandler(this, &Form1::btnOpen_Click);

//panel1
            this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panel1->Controls->Add(this->btnClose);
			this->panel1->Location = System::Drawing::Point(-625, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(312, 515);
			this->panel1->TabIndex = 27;
//btnClose
            	this->btnClose->Location = System::Drawing::Point(234, 23);
			this->btnClose->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(60, 22);
			this->btnClose->TabIndex = 0;
			this->btnClose->Text = L"Close";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &Form1::btnClose_Click);
//Form1
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(620, 505);

            this->Controls->Add(this->panel1);
            this->Controls->Add(this->btnOpen);
            this->Controls->Add(this->btnClose);

            this->Name = L"Form1";
			this->Text = L"Sliding Panel";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
            this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();


        }
#pragma endregion

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {


			 }


             private: System::Void btnOpen_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 panel1->Location=Point(-625,0);
				 while(panel1->Location.X!=0)
				 {
					 panel1->Location=Point(panel1->Location.X+1,0);
					 System::Threading::Thread::Sleep(10);
				 }
			 }
	private: System::Void btnClose_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 panel1->Location=Point(0,0);
				 while(panel1->Location.X!=-625)
				 {
					 panel1->Location=Point(panel1->Location.X-1,0);
					 System::Threading::Thread::Sleep(5);
				 }
			 }


    };
}
