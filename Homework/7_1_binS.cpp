int BinarySearch(struct Address list[], char *key , int end ) {
	int Low, Mid, High;
	Low = 0; High = end - 1;
	while( Low <= High ) {
		Mid = ( Low + High ) / 2;
		if( strcmp(list[ Mid ].name, key) < 0 )
			Low = Mid + 1;
		else if(strcmp(list[ Mid ].name, key) > 0)
			High = Mid - 1;
		else
			return Mid;
	}
	return -1;
}