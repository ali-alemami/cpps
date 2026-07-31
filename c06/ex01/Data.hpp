#ifndef DATA_HPP
#define DATA_HPP

class Data
{
	private:
		int		_value;
		Data	*_next;
	
	public:
		Data();
		Data(int value);
		Data(const Data& other);
		Data&	operator=(const Data& other);
		~Data();
};

#endif