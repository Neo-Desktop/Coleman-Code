

void ChangeConsoleTitle (const TCHAR* input);

void ChangeConsoleIcon (int resource_number);

void ConsoleSetup(TCHAR* input);

int GetYear();

enum { NUL = 0, SOH, STX, ETX, EOT, ENQ, ACK, BEL, BS, HT,
	   LF, VT, FF, CR, SO, SI, DLE, DC1, DC2, DC3, DC4, NAK, 
	   SYN, ETB, CAN, EM, SUB, ESC, FS, GS, RS, US, DEL = 127 };