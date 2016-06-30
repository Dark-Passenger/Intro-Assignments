/*Class defination to be included. To reduce code duplication adding it to a header file.*/
class sharedclass 
{

private:
	int result;

public:
	sharedclass();
	int add(int a, int b);
	int subtract(int a, int b);
	int multiply(int a, int b);
	int divide(int a, int b);
};
