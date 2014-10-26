/* Given a string s and an array of smaller strings T, design a method to search s for each small string in T. */Given a string s and an array of smaller strings T, design a method to search s for each small string in T.*/

/*
suffix tree for bananas (construct from the end)

			                *
		/		|		|		\
             bananas            na              a		 s
                               /   \          /   \
			      nas   s        na    s
			                    /  \
				           s   nas
*/