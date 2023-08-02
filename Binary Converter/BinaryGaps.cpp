// Include the libraries required for the program to work

#include <math.h>
#include <iostream>
#include "BinaryGaps.h"

using namespace BinaryConverter;
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    ref class BinaryConverter::BinaryGaps form;
    Application::Run(% form);
}
