#ifndef D_HEXCONVERT_H_INCLUDED
#define D_HEXCONVERT_H_INCLUDED
void displayInBase (int n, int base)
{
	if(n>0)
	{
		// �ݹ����
		displayInBase(n/base,base);
		cout << n % base;
	}
}


#endif // D_HEXCONVERT_H_INCLUDED
