#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

    using namespace MySql::Data::MySqlClient;

	public ref class Form1 : public System::Windows::Forms::Form
	{
        MySqlConnection^ conn = gcnew MySqlConnection();
        MySqlCommand^ cmd = gcnew MySqlCommand();
        DataTable^ dt = gcnew DataTable();
        MySqlDataAdapter^ da = gcnew MySqlDataAdapter();
        MySqlDataReader^ dr;

    private:
        bool movingForm = false;
        Point mousePosition;

	public:
		Form1(void)
		{
			InitializeComponent();
            xcrud();
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::Button^ btnClear;
    protected:
    private: System::Windows::Forms::Button^ btnDelete;
    private: System::Windows::Forms::Button^ btnUpdate;
    private: System::Windows::Forms::Button^ btnRead;
    private: System::Windows::Forms::Button^ btnCreate;
    private: System::Windows::Forms::Panel^ pnlID;
    private: System::Windows::Forms::TextBox^ txtID;
    private: System::Windows::Forms::Label^ label8;
    private: System::Windows::Forms::ComboBox^ cmbGender;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::Panel^ pnlEmail;
    private: System::Windows::Forms::TextBox^ txtEmail;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::Panel^ pnlDOB;
    private: System::Windows::Forms::DateTimePicker^ dtpDOB;
    private: System::Windows::Forms::Panel^ pnlPhoneNumber;
    private: System::Windows::Forms::TextBox^ txtPhoneNumber;
    private: System::Windows::Forms::Panel^ pnlAddress;
    private: System::Windows::Forms::TextBox^ txtAddress;
    private: System::Windows::Forms::Panel^ pnlLastName;
    private: System::Windows::Forms::TextBox^ txtLastName;
    private: System::Windows::Forms::Panel^ pnlFirstName;
    private: System::Windows::Forms::TextBox^ txtFirstName;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::DataGridView^ dgvRegistry;
    private: System::Windows::Forms::Panel^ pnlMove;
    private: System::Windows::Forms::PictureBox^ picMinimize;
    private: System::Windows::Forms::PictureBox^ picClose;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
            this->btnClear = (gcnew System::Windows::Forms::Button());
            this->btnDelete = (gcnew System::Windows::Forms::Button());
            this->btnUpdate = (gcnew System::Windows::Forms::Button());
            this->btnRead = (gcnew System::Windows::Forms::Button());
            this->btnCreate = (gcnew System::Windows::Forms::Button());
            this->pnlID = (gcnew System::Windows::Forms::Panel());
            this->txtID = (gcnew System::Windows::Forms::TextBox());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->cmbGender = (gcnew System::Windows::Forms::ComboBox());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->pnlEmail = (gcnew System::Windows::Forms::Panel());
            this->txtEmail = (gcnew System::Windows::Forms::TextBox());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->pnlDOB = (gcnew System::Windows::Forms::Panel());
            this->dtpDOB = (gcnew System::Windows::Forms::DateTimePicker());
            this->pnlPhoneNumber = (gcnew System::Windows::Forms::Panel());
            this->txtPhoneNumber = (gcnew System::Windows::Forms::TextBox());
            this->pnlAddress = (gcnew System::Windows::Forms::Panel());
            this->txtAddress = (gcnew System::Windows::Forms::TextBox());
            this->pnlLastName = (gcnew System::Windows::Forms::Panel());
            this->txtLastName = (gcnew System::Windows::Forms::TextBox());
            this->pnlFirstName = (gcnew System::Windows::Forms::Panel());
            this->txtFirstName = (gcnew System::Windows::Forms::TextBox());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->dgvRegistry = (gcnew System::Windows::Forms::DataGridView());
            this->pnlMove = (gcnew System::Windows::Forms::Panel());
            this->picMinimize = (gcnew System::Windows::Forms::PictureBox());
            this->picClose = (gcnew System::Windows::Forms::PictureBox());
            this->pnlID->SuspendLayout();
            this->pnlEmail->SuspendLayout();
            this->pnlDOB->SuspendLayout();
            this->pnlPhoneNumber->SuspendLayout();
            this->pnlAddress->SuspendLayout();
            this->pnlLastName->SuspendLayout();
            this->pnlFirstName->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRegistry))->BeginInit();
            this->pnlMove->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimize))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picClose))->BeginInit();
            this->SuspendLayout();
            // 
            // btnClear
            // 
            this->btnClear->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(95)));
            this->btnClear->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnClear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnClear->Font = (gcnew System::Drawing::Font(L"Corbel", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnClear->ForeColor = System::Drawing::Color::GreenYellow;
            this->btnClear->Location = System::Drawing::Point(633, 285);
            this->btnClear->Name = L"btnClear";
            this->btnClear->Size = System::Drawing::Size(75, 23);
            this->btnClear->TabIndex = 45;
            this->btnClear->Text = L"CLEAR";
            this->btnClear->UseVisualStyleBackColor = false;
            this->btnClear->Click += gcnew System::EventHandler(this, &Form1::btnClear_Click);
            // 
            // btnDelete
            // 
            this->btnDelete->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(95)));
            this->btnDelete->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnDelete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnDelete->Font = (gcnew System::Drawing::Font(L"Corbel", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnDelete->ForeColor = System::Drawing::Color::GreenYellow;
            this->btnDelete->Location = System::Drawing::Point(501, 285);
            this->btnDelete->Name = L"btnDelete";
            this->btnDelete->Size = System::Drawing::Size(75, 23);
            this->btnDelete->TabIndex = 44;
            this->btnDelete->Text = L"DELETE";
            this->btnDelete->UseVisualStyleBackColor = false;
            this->btnDelete->Click += gcnew System::EventHandler(this, &Form1::btnDelete_Click);
            // 
            // btnUpdate
            // 
            this->btnUpdate->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(95)));
            this->btnUpdate->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnUpdate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnUpdate->Font = (gcnew System::Drawing::Font(L"Corbel", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnUpdate->ForeColor = System::Drawing::Color::GreenYellow;
            this->btnUpdate->Location = System::Drawing::Point(420, 285);
            this->btnUpdate->Name = L"btnUpdate";
            this->btnUpdate->Size = System::Drawing::Size(75, 23);
            this->btnUpdate->TabIndex = 43;
            this->btnUpdate->Text = L"UPDATE";
            this->btnUpdate->UseVisualStyleBackColor = false;
            this->btnUpdate->Click += gcnew System::EventHandler(this, &Form1::btnUpdate_Click);
            // 
            // btnRead
            // 
            this->btnRead->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(95)));
            this->btnRead->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnRead->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnRead->Font = (gcnew System::Drawing::Font(L"Corbel", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnRead->ForeColor = System::Drawing::Color::GreenYellow;
            this->btnRead->Location = System::Drawing::Point(339, 285);
            this->btnRead->Name = L"btnRead";
            this->btnRead->Size = System::Drawing::Size(75, 23);
            this->btnRead->TabIndex = 42;
            this->btnRead->Text = L"READ";
            this->btnRead->UseVisualStyleBackColor = false;
            this->btnRead->Click += gcnew System::EventHandler(this, &Form1::btnRead_Click);
            // 
            // btnCreate
            // 
            this->btnCreate->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(95)));
            this->btnCreate->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnCreate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnCreate->Font = (gcnew System::Drawing::Font(L"Corbel", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnCreate->ForeColor = System::Drawing::Color::GreenYellow;
            this->btnCreate->Location = System::Drawing::Point(258, 285);
            this->btnCreate->Name = L"btnCreate";
            this->btnCreate->Size = System::Drawing::Size(75, 23);
            this->btnCreate->TabIndex = 41;
            this->btnCreate->Text = L"CREATE";
            this->btnCreate->UseVisualStyleBackColor = false;
            this->btnCreate->Click += gcnew System::EventHandler(this, &Form1::btnCreate_Click);
            // 
            // pnlID
            // 
            this->pnlID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)), static_cast<System::Int32>(static_cast<System::Byte>(95)),
                static_cast<System::Int32>(static_cast<System::Byte>(154)));
            this->pnlID->Controls->Add(this->txtID);
            this->pnlID->Location = System::Drawing::Point(166, 62);
            this->pnlID->Name = L"pnlID";
            this->pnlID->Size = System::Drawing::Size(136, 23);
            this->pnlID->TabIndex = 30;
            // 
            // txtID
            // 
            this->txtID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(95)));
            this->txtID->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtID->Font = (gcnew System::Drawing::Font(L"Corbel", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txtID->ForeColor = System::Drawing::Color::MediumTurquoise;
            this->txtID->Location = System::Drawing::Point(5, 4);
            this->txtID->Name = L"txtID";
            this->txtID->Size = System::Drawing::Size(126, 16);
            this->txtID->TabIndex = 6;
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Font = (gcnew System::Drawing::Font(L"Corbel", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label8->ForeColor = System::Drawing::Color::GreenYellow;
            this->label8->Location = System::Drawing::Point(15, 62);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(34, 23);
            this->label8->TabIndex = 40;
            this->label8->Text = L"ID:";
            // 
            // cmbGender
            // 
            this->cmbGender->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)), static_cast<System::Int32>(static_cast<System::Byte>(95)),
                static_cast<System::Int32>(static_cast<System::Byte>(154)));
            this->cmbGender->Font = (gcnew System::Drawing::Font(L"Corbel", 9.75F, System::Drawing::FontStyle::Bold));
            this->cmbGender->ForeColor = System::Drawing::Color::MediumTurquoise;
            this->cmbGender->FormattingEnabled = true;
            this->cmbGender->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Male", L"Female" });
            this->cmbGender->Location = System::Drawing::Point(628, 199);
            this->cmbGender->Name = L"cmbGender";
            this->cmbGender->Size = System::Drawing::Size(136, 23);
            this->cmbGender->TabIndex = 39;
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Font = (gcnew System::Drawing::Font(L"Corbel", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label7->ForeColor = System::Drawing::Color::GreenYellow;
            this->label7->Location = System::Drawing::Point(477, 200);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(78, 23);
            this->label7->TabIndex = 38;
            this->label7->Text = L"Gender:";
            // 
            // pnlEmail
            // 
            this->pnlEmail->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)), static_cast<System::Int32>(static_cast<System::Byte>(95)),
                static_cast<System::Int32>(static_cast<System::Byte>(154)));
            this->pnlEmail->Controls->Add(this->txtEmail);
            this->pnlEmail->Location = System::Drawing::Point(628, 154);
            this->pnlEmail->Name = L"pnlEmail";
            this->pnlEmail->Size = System::Drawing::Size(295, 23);
            this->pnlEmail->TabIndex = 37;
            // 
            // txtEmail
            // 
            this->txtEmail->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(95)));
            this->txtEmail->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtEmail->Font = (gcnew System::Drawing::Font(L"Corbel", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txtEmail->ForeColor = System::Drawing::Color::MediumTurquoise;
            this->txtEmail->Location = System::Drawing::Point(5, 4);
            this->txtEmail->Name = L"txtEmail";
            this->txtEmail->Size = System::Drawing::Size(285, 16);
            this->txtEmail->TabIndex = 6;
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Font = (gcnew System::Drawing::Font(L"Corbel", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label6->ForeColor = System::Drawing::Color::GreenYellow;
            this->label6->Location = System::Drawing::Point(477, 154);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(63, 23);
            this->label6->TabIndex = 36;
            this->label6->Text = L"Email:";
            // 
            // pnlDOB
            // 
            this->pnlDOB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)), static_cast<System::Int32>(static_cast<System::Byte>(95)),
                static_cast<System::Int32>(static_cast<System::Byte>(154)));
            this->pnlDOB->Controls->Add(this->dtpDOB);
            this->pnlDOB->Location = System::Drawing::Point(628, 108);
            this->pnlDOB->Name = L"pnlDOB";
            this->pnlDOB->Size = System::Drawing::Size(204, 23);
            this->pnlDOB->TabIndex = 34;
            // 
            // dtpDOB
            // 
            this->dtpDOB->CalendarForeColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->dtpDOB->CalendarMonthBackground = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)),
                static_cast<System::Int32>(static_cast<System::Byte>(95)), static_cast<System::Int32>(static_cast<System::Byte>(154)));
            this->dtpDOB->Location = System::Drawing::Point(2, 2);
            this->dtpDOB->Name = L"dtpDOB";
            this->dtpDOB->Size = System::Drawing::Size(200, 20);
            this->dtpDOB->TabIndex = 12;
            // 
            // pnlPhoneNumber
            // 
            this->pnlPhoneNumber->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)), static_cast<System::Int32>(static_cast<System::Byte>(95)),
                static_cast<System::Int32>(static_cast<System::Byte>(154)));
            this->pnlPhoneNumber->Controls->Add(this->txtPhoneNumber);
            this->pnlPhoneNumber->Location = System::Drawing::Point(628, 62);
            this->pnlPhoneNumber->Name = L"pnlPhoneNumber";
            this->pnlPhoneNumber->Size = System::Drawing::Size(295, 23);
            this->pnlPhoneNumber->TabIndex = 33;
            // 
            // txtPhoneNumber
            // 
            this->txtPhoneNumber->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(95)));
            this->txtPhoneNumber->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtPhoneNumber->Font = (gcnew System::Drawing::Font(L"Corbel", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txtPhoneNumber->ForeColor = System::Drawing::Color::MediumTurquoise;
            this->txtPhoneNumber->Location = System::Drawing::Point(5, 4);
            this->txtPhoneNumber->Name = L"txtPhoneNumber";
            this->txtPhoneNumber->Size = System::Drawing::Size(285, 16);
            this->txtPhoneNumber->TabIndex = 6;
            // 
            // pnlAddress
            // 
            this->pnlAddress->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)), static_cast<System::Int32>(static_cast<System::Byte>(95)),
                static_cast<System::Int32>(static_cast<System::Byte>(154)));
            this->pnlAddress->Controls->Add(this->txtAddress);
            this->pnlAddress->Location = System::Drawing::Point(166, 202);
            this->pnlAddress->Name = L"pnlAddress";
            this->pnlAddress->Size = System::Drawing::Size(295, 23);
            this->pnlAddress->TabIndex = 32;
            // 
            // txtAddress
            // 
            this->txtAddress->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(95)));
            this->txtAddress->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtAddress->Font = (gcnew System::Drawing::Font(L"Corbel", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txtAddress->ForeColor = System::Drawing::Color::MediumTurquoise;
            this->txtAddress->Location = System::Drawing::Point(5, 4);
            this->txtAddress->Name = L"txtAddress";
            this->txtAddress->Size = System::Drawing::Size(285, 16);
            this->txtAddress->TabIndex = 6;
            // 
            // pnlLastName
            // 
            this->pnlLastName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)), static_cast<System::Int32>(static_cast<System::Byte>(95)),
                static_cast<System::Int32>(static_cast<System::Byte>(154)));
            this->pnlLastName->Controls->Add(this->txtLastName);
            this->pnlLastName->Location = System::Drawing::Point(166, 156);
            this->pnlLastName->Name = L"pnlLastName";
            this->pnlLastName->Size = System::Drawing::Size(295, 23);
            this->pnlLastName->TabIndex = 31;
            // 
            // txtLastName
            // 
            this->txtLastName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(95)));
            this->txtLastName->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtLastName->Font = (gcnew System::Drawing::Font(L"Corbel", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txtLastName->ForeColor = System::Drawing::Color::MediumTurquoise;
            this->txtLastName->Location = System::Drawing::Point(5, 4);
            this->txtLastName->Name = L"txtLastName";
            this->txtLastName->Size = System::Drawing::Size(285, 16);
            this->txtLastName->TabIndex = 6;
            // 
            // pnlFirstName
            // 
            this->pnlFirstName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)), static_cast<System::Int32>(static_cast<System::Byte>(95)),
                static_cast<System::Int32>(static_cast<System::Byte>(154)));
            this->pnlFirstName->Controls->Add(this->txtFirstName);
            this->pnlFirstName->Location = System::Drawing::Point(166, 110);
            this->pnlFirstName->Name = L"pnlFirstName";
            this->pnlFirstName->Size = System::Drawing::Size(295, 23);
            this->pnlFirstName->TabIndex = 29;
            // 
            // txtFirstName
            // 
            this->txtFirstName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(95)));
            this->txtFirstName->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtFirstName->Font = (gcnew System::Drawing::Font(L"Corbel", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txtFirstName->ForeColor = System::Drawing::Color::MediumTurquoise;
            this->txtFirstName->Location = System::Drawing::Point(5, 4);
            this->txtFirstName->Name = L"txtFirstName";
            this->txtFirstName->Size = System::Drawing::Size(285, 16);
            this->txtFirstName->TabIndex = 6;
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Corbel", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label5->ForeColor = System::Drawing::Color::GreenYellow;
            this->label5->Location = System::Drawing::Point(474, 108);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(123, 23);
            this->label5->TabIndex = 28;
            this->label5->Text = L"Date of Birth:";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Corbel", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label4->ForeColor = System::Drawing::Color::GreenYellow;
            this->label4->Location = System::Drawing::Point(474, 62);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(142, 23);
            this->label4->TabIndex = 27;
            this->label4->Text = L"Phone Number:";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Corbel", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->ForeColor = System::Drawing::Color::GreenYellow;
            this->label3->Location = System::Drawing::Point(12, 202);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(83, 23);
            this->label3->TabIndex = 26;
            this->label3->Text = L"Address:";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Corbel", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->ForeColor = System::Drawing::Color::GreenYellow;
            this->label2->Location = System::Drawing::Point(12, 156);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(105, 23);
            this->label2->TabIndex = 25;
            this->label2->Text = L"Last Name:";
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Corbel", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::Color::GreenYellow;
            this->label1->Location = System::Drawing::Point(12, 110);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(107, 23);
            this->label1->TabIndex = 24;
            this->label1->Text = L"First Name:";
            // 
            // dgvRegistry
            // 
            this->dgvRegistry->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->dgvRegistry->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->dgvRegistry->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)),
                static_cast<System::Int32>(static_cast<System::Byte>(95)), static_cast<System::Int32>(static_cast<System::Byte>(154)));
            this->dgvRegistry->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvRegistry->Location = System::Drawing::Point(26, 326);
            this->dgvRegistry->Name = L"dgvRegistry";
            this->dgvRegistry->RowHeadersWidth = 30;
            this->dgvRegistry->Size = System::Drawing::Size(889, 210);
            this->dgvRegistry->TabIndex = 35;
            this->dgvRegistry->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dgvRegistry_CellClick);
            // 
            // pnlMove
            // 
            this->pnlMove->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)), static_cast<System::Int32>(static_cast<System::Byte>(95)),
                static_cast<System::Int32>(static_cast<System::Byte>(154)));
            this->pnlMove->Controls->Add(this->picMinimize);
            this->pnlMove->Controls->Add(this->picClose);
            this->pnlMove->Location = System::Drawing::Point(-1, 0);
            this->pnlMove->Name = L"pnlMove";
            this->pnlMove->Size = System::Drawing::Size(944, 29);
            this->pnlMove->TabIndex = 23;
            this->pnlMove->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pnlMove_MouseDown);
            this->pnlMove->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pnlMove_MouseMove);
            this->pnlMove->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pnlMove_MouseUp);
            // 
            // picMinimize
            // 
            this->picMinimize->Image = Image::FromFile("minimize.png");
            this->picMinimize->Location = System::Drawing::Point(883, 2);
            this->picMinimize->Name = L"picMinimize";
            this->picMinimize->Size = System::Drawing::Size(25, 25);
            this->picMinimize->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->picMinimize->TabIndex = 1;
            this->picMinimize->TabStop = false;
            this->picMinimize->Click += gcnew System::EventHandler(this, &Form1::picMinimize_Click);
            // 
            // picClose
            // 
            this->picClose->Image = Image::FromFile("close.png");
            this->picClose->Location = System::Drawing::Point(914, 2);
            this->picClose->Name = L"picClose";
            this->picClose->Size = System::Drawing::Size(25, 25);
            this->picClose->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->picClose->TabIndex = 1;
            this->picClose->TabStop = false;
            this->picClose->Click += gcnew System::EventHandler(this, &Form1::picClose_Click);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(79)));
            this->ClientSize = System::Drawing::Size(940, 554);
            this->Controls->Add(this->btnClear);
            this->Controls->Add(this->btnDelete);
            this->Controls->Add(this->btnUpdate);
            this->Controls->Add(this->btnRead);
            this->Controls->Add(this->btnCreate);
            this->Controls->Add(this->pnlID);
            this->Controls->Add(this->label8);
            this->Controls->Add(this->cmbGender);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->pnlEmail);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->pnlDOB);
            this->Controls->Add(this->pnlPhoneNumber);
            this->Controls->Add(this->pnlAddress);
            this->Controls->Add(this->pnlLastName);
            this->Controls->Add(this->pnlFirstName);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->dgvRegistry);
            this->Controls->Add(this->pnlMove);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Name = L"Form1";
            this->Text = L"Form1";
            this->pnlID->ResumeLayout(false);
            this->pnlID->PerformLayout();
            this->pnlEmail->ResumeLayout(false);
            this->pnlEmail->PerformLayout();
            this->pnlDOB->ResumeLayout(false);
            this->pnlPhoneNumber->ResumeLayout(false);
            this->pnlPhoneNumber->PerformLayout();
            this->pnlAddress->ResumeLayout(false);
            this->pnlAddress->PerformLayout();
            this->pnlLastName->ResumeLayout(false);
            this->pnlLastName->PerformLayout();
            this->pnlFirstName->ResumeLayout(false);
            this->pnlFirstName->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRegistry))->EndInit();
            this->pnlMove->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimize))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picClose))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private:
        System::Void xcrud() {
            conn->ConnectionString = "datasource=localhost; port=3306; username=root; password=yourPassword; database=databaseName";
            conn->Open();
            cmd->Connection = conn;
            cmd->CommandText = "select * from users";
            dr = cmd->ExecuteReader();
            dt->Load(dr);
            dr->Close();
            conn->Close();
            dgvRegistry->DataSource = dt;
        }
    private:
        System::Void refresh() {
            try {
                conn->ConnectionString = "datasource=localhost; port=3306; username=root; password=yourPassword; database=databaseName";
                cmd->Connection = conn;

                MySqlDataAdapter^ da = gcnew MySqlDataAdapter("select * from users", conn);
                DataTable^ dt = gcnew DataTable();
                da->Fill(dt);
                conn->Close();
                dgvRegistry->DataSource = dt;
            }
            catch (Exception^ ex) {
                MessageBox::Show(ex->Message, "Data Entry Form", MessageBoxButtons::YesNo, MessageBoxIcon::Information);
            }
        }
    private: System::Void btnCreate_Click(System::Object^ sender, System::EventArgs^ e) {
        conn->ConnectionString = "datasource=localhost; port=3306; username=root; password=yourPassword; database=databaseName";
        conn->Open();
        cmd->Connection = conn;
        try {
            cmd->CommandText = "INSERT INTO users(FirstName, LastName, Address, PhoneNumber, " +
                "DateOfBirth, Email, Gender) VALUES('" + txtFirstName->Text + "','" + txtLastName->Text + "', '" +
                txtAddress->Text + "', '" + txtPhoneNumber->Text + "', '" + dtpDOB->Text + "', '" +
                txtEmail->Text + "', '" + cmbGender->Text + "')";
            cmd->ExecuteNonQuery();
            dr->Close();
            conn->Close();
            xcrud();
            refresh();
        }
        catch (Exception^ ex) {
            MessageBox::Show(ex->Message, "Data Entry Form", MessageBoxButtons::YesNo, MessageBoxIcon::Information);
        }
    }
    private: System::Void btnRead_Click(System::Object^ sender, System::EventArgs^ e) {
        refresh();
    }
    private: System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            conn->ConnectionString = "datasource=localhost; port=3306; username=root; password=yourPassword; database=databaseName";
            cmd->Connection = conn;

            String^ ID = txtID->Text;
            String^ FirstName = txtFirstName->Text;
            String^ LastName = txtLastName->Text;
            String^ Address = txtAddress->Text;
            String^ PhoneNumber = txtPhoneNumber->Text;
            String^ DOB = dtpDOB->Text;
            String^ Email = txtEmail->Text;
            String^ Gender = cmbGender->Text;

            cmd->CommandText = "UPDATE users set FirstName='" + FirstName + "', LastName='" + LastName +
                "', Address='" + Address + "', PhoneNumber='" + PhoneNumber + "', DateOfBirth='" + DOB +
                "', Email='" + Email + "', Gender='" + Gender + "' WHERE ID=" + ID + "";
            conn->Open();
            dr = cmd->ExecuteReader();
            conn->Close();
            xcrud();
            refresh();
        }
        catch (Exception^ ex) {
            MessageBox::Show(ex->Message, "Data Entry Form", MessageBoxButtons::YesNo, MessageBoxIcon::Information);
        }
        conn->Close();
    }
    private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            conn->ConnectionString = "datasource=localhost; port=3306; username=root; password=yourPassword; database=databaseName";
            cmd->Connection = conn;
            String^ ID = txtID->Text;
            cmd = gcnew MySqlCommand("DELETE FROM users WHERE ID=" + ID + "", conn);
            conn->Open();

            dr = cmd->ExecuteReader();
            MessageBox::Show("Recorded Deleted", "Data Entry Form", MessageBoxButtons::YesNo, MessageBoxIcon::Information);
            conn->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show(ex->Message, "Data Entry Form", MessageBoxButtons::YesNo, MessageBoxIcon::Information);
        }
    }
    private: System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            txtID->Text = "";
            txtFirstName->Text = "";
            txtLastName->Text = "";
            txtAddress->Text = "";
            txtPhoneNumber->Text = "";
            dtpDOB->Text = "";
            txtEmail->Text = "";
            cmbGender->Text = "";
        }
        catch (Exception^ ex) {
            MessageBox::Show(ex->Message, "Data Entry Form", MessageBoxButtons::YesNo, MessageBoxIcon::Information);
        }
    }
    private: System::Void pnlMove_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        movingForm = true;
        mousePosition = Point(e->X, e->Y);
    }
    private: System::Void pnlMove_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        if (movingForm) {
            this->Location = Point(this->Location.X + e->X - mousePosition.X, this->Location.Y + e->Y - mousePosition.Y);
        }
    }
    private: System::Void pnlMove_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        movingForm = false;
    }
    private: System::Void picClose_Click(System::Object^ sender, System::EventArgs^ e) {
        System::Windows::Forms::DialogResult iExit;
        try {
            iExit = MessageBox::Show("Confirm if you want to exit", "Data Entry Form", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
            if (iExit == System::Windows::Forms::DialogResult::Yes) {
                Application::Exit();
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show(ex->Message, "Data Entry Form", MessageBoxButtons::YesNo, MessageBoxIcon::Information);
        }
    }
    private: System::Void picMinimize_Click(System::Object^ sender, System::EventArgs^ e) {
        this->WindowState = FormWindowState::Minimized;
    }
    private: System::Void dgvRegistry_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        try {
            txtID->Text = dgvRegistry->SelectedRows[0]->Cells[0]->Value->ToString();
            txtFirstName->Text = dgvRegistry->SelectedRows[0]->Cells[1]->Value->ToString();
            txtLastName->Text = dgvRegistry->SelectedRows[0]->Cells[2]->Value->ToString();
            txtAddress->Text = dgvRegistry->SelectedRows[0]->Cells[3]->Value->ToString();
            txtPhoneNumber->Text = dgvRegistry->SelectedRows[0]->Cells[4]->Value->ToString();
            dtpDOB->Text = dgvRegistry->SelectedRows[0]->Cells[5]->Value->ToString();
            txtEmail->Text = dgvRegistry->SelectedRows[0]->Cells[6]->Value->ToString();
            cmbGender->Text = dgvRegistry->SelectedRows[0]->Cells[7]->Value->ToString();
        }
        catch (Exception^ ex) {
            MessageBox::Show(ex->Message, "Data Entry Form", MessageBoxButtons::YesNo, MessageBoxIcon::Information);
        }

    }
};
}
