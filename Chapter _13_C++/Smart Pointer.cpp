// copied from the book 
// only Bloomberg asks this type of question

template <class T> 
class SmartPointer {

protected:
	T *ref;
	unsigned *ref_count;

public:
	SmartPointer(T *ptr) { // constructor
		ref = ptr;
		ref_count = (unsigned*)malloc(sizeof(unsigned));
		*ref_count = 1;
	}

	SmartPointer(SmartPointer<T> &sptr) { // copy constructor
		ref = sptr.ref;
		ref_count = sptr.ref_count;
		++*ref_count;
	}

	SmartPointer<T> & operator=(SmartPointer<T> &sptr) { // assignemnt operator
		if (this != &sptr) {
			ref = sptr.ref;
			ref_count = sptr.ref_count;
			++*ref_count;
		}
		return *this;
	}

	~SmartPointer() {  // destructor
		--*ref_count;
		if (*ref_count == 0) {
			delete ref;
			free(ref_count);
			ref = NULL;
			ref_count = NULL;
		}
	}

	T getValue() { 
		return *ref; 
	}
};