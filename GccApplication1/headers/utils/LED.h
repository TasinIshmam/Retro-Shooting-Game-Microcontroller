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