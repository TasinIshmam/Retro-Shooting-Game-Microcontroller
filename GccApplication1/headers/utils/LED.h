///** pass 'A','B','C','D' in capital case as portX/portY to choose the ports  **/
//
void ledPrint(char x, char portX, char y, char portY)
{
    //x = (x % MATRIX_SIZE + MATRIX_SIZE) % MATRIX_SIZE;
    if (x < 0 || y < 0)
        return;
    switch (portX)
    {
    case 'A':
        PORTA = ~(1 << x);
        break;
    case 'B':
        PORTB = ~(1 << x);
        break;
    case 'C':
        PORTC = ~(1 << x);
        break;
    case 'D':
        PORTD = ~(1 << x);
        break;
    }
    switch (portY)
    {
    case 'A':
        PORTA = (1 << y);
        break;
    case 'B':
        PORTB = (1 << y);
        break;
    case 'C':
        PORTC = (1 << y);
        break;
    case 'D':
        PORTD = (1 << y);
        break;
    }
}


//port A has 8 bits
//DC R3 R2 R1 R0 c2 c1 c0s
//7  6  5  4  3  2  1  0   -> Bit number of portA.
 
 //x goes to 8 to 3 decoder
 //y goes to 16 to 4 decoder
void ledPrintUsingDecoder(char x, char y, char portName) {
  
    if (x < 0 || y < 0)
        { 
            return; 
        }
    char newY = y << 3;

    char res = newY | x;
  

    switch (portName)
    {
    case 'A':
        PORTA = res;
        break;
    case 'B':
        PORTB = res;
        break;
    case 'C':
        PORTC = res;
        break;
    case 'D':
        PORTD = res;
        break;
    }
}
