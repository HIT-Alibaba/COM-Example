// MyClass.cpp : CMyClass 的实现

#include "stdafx.h"
#include "MyClass.h"


// CMyClass



STDMETHODIMP CMyClass::IsValidNum(CHAR* str, BYTE* result)
{
	//*result = 0;
	if (!str)
	{
		*result =100;
		return S_OK;
	}
    while(str[0]==' ') ++str;
    while(str[strlen(str)-1]==' ') str[strlen(str)-1]='\0';
    bool canSign=true, canE=false, wasE=false, canDot=true, wasDot=false, aftE=false, wasNum=false;
    int n=strlen(str);
    for (int i=0; i<n;++i)
    {
        if ((str[i]=='+')||(str[i]=='-'))
            if (canSign)
            {
                canSign = false;
                canE = false;
            }
            else
			{
			*result = 100;
			return S_OK;
			}
		else
        if ((str[i]>='0')&&(str[i]<='9'))
        {
            canSign = false;
            canDot = true;
            canE = true;
            aftE = false;
            wasNum= true;
        }
        else
        if (str[i]=='e')
            if ((!canE)||(wasE))
            {
			*result = 100;
			return S_OK;
			}
            else
            {
                wasE=true;
                canSign=true;
                aftE=true;
            }
			else
        if (str[i]=='.')
        {
            if ((!canDot)||(wasDot)||(wasE))
			{
			*result = -1;
			return S_OK;
			}
            else
            {
                canSign = false;
                wasDot = true;
            }
        }
        else
        {
			*result = 100;
			return S_OK;
		}
    }

	if(!aftE&&wasNum)
		*result = 1;
	else 
		*result =100;

    return S_OK;

	/*//byte flg=0;
	// TODO: 在此添加实现代码
	bool left = true;
    // ignore the space before start
    while (*str == ' ') str++;

    // There could be 1 '+'/'-' before the first number
    if (*str && (*str == '+' || *str == '-')) str++;

	// the first element could be . or number, (there must be a number before e, so e is not valid)
    if (*str == '.'){
        left = false;
    }
    else if (*str < 48 || *str > 57){
		*result =-1;
        return S_OK;
    }
    else {
        while (*str >= 48 && *str <= 57) str++;
    }

	// after first step, all the number before . or e has been processed.
    // 3 cases, all the number is over; . ; e
    if (!*str || *str == ' '){}
    // there could be a '+'/'-' after e. But after that, the remaining number must be a positive integer (no ., no e, no +-).
    else if (*str == 'e'){
        str++;
        if (*str == '+' || *str == '-') str++;
		if (!*str || *str == ' ') 
		{
			*result =-1;
			return S_OK;
		}
        while (*str >= 48 && *str <= 57) str++;
    }
	// the dot is a little bit complicated
    // (1) The left or right part of . could be null, but not both (So I used bool left to record that).
    // (2) after dot, check if left is empty, if left is empty, then the right side must be a number.
    // (3) if left is not empty, then the right side could be a number with e. Repeat the case above.
    else if (*str == '.'){
        str++;
		if ((*str < 48 || *str > 57) && !left)
		{
			*result =-1;
			return S_OK;
		}
        while (*str >= 48 && *str <= 57) str++;
        if (*str == 'e') {
            str++;
            if (*str == '+' || *str == '-') str++;
            if (!*str || *str == ' ')
			{
				*result =-1;
				return S_OK;
			}
            while (*str >= 48 && *str <= 57) str++;
        }
    }
    // other case return false;
    else
	{
		*result =-1;
        return S_OK;
	}

	// deal with the space after all the number
    while (*str && *str == ' ') str++;

    // Still not end? Goodbye!
    if (*str)
	{
		*result =-1;
        return S_OK;
	}

    // Succeed.
	*result =1;
	return S_OK;*/
}
