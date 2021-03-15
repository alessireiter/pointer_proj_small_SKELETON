#include <string.h>
#include <iostream>
#include "../includes/constants.h"
#include "../includes/stringmanip.h"

using namespace std;

namespace KP{

/**
	 * Calculate the exact amount of memory needed to allocate a that consists of the old string with all tags replaced by tag_replacements.
	 * Don't forget the terminating null!
	 *
	 * ex. src="a large ship"
	 *     tag="large"
	 *     tag_replacement="really large"
	 *
	 *     then
	 *     len_src = 14
	 *     numbTagsToReplace=1
	 *     len_tag=5
	 *     len_tag_replacement=12
	 *
	 *     the function should return 22
	 *
	 * \param len_src - length of original string
	 * \param numbTagsToReplace - number of tags to replace in the original string
	 * \param len_tag - length of the tag
	 * \param len_tag_replacement - length of the tag replacement
	 * \return
	 */
	int amountOfMemoryToAllocateForNewString(int len_src, int numbTagsToReplace, int len_tag, int len_tag_replacement){
		return len_src - (numbTagsToReplace * len_tag) + (numbTagsToReplace * len_tag_replacement);
	}

	/**
		 * If src,new_src, tag or tag_replacment are null then returns INVALID_NULL_PTR_DETECTED
		 *
		 * Copies src char string to new_src char string, replaces all tag occurrences with tag_replacement.
		 * Please ensure that new_src is allocated and of proper size before calling this function
		 *
		 * ex.
		 * 	src ="a large bucket on a large ship"
			tag="large"
			tag_replacement="really large"
			then when the function returns
			new_src="a really large bucket on a really large ship"
		 *
		 * \param src  initial char string, may be deleted and reallocated by this function
		 * \param new_src char string with enough space to hold src string with all tag occurrences replaced by tag_replacement
		 * \param tag  the tag to search for
		 * \param tag_replacement  replaces all occurrences of tag
		 * \return INVALID_NULL_PTR_DETECTED one or more of src, tag or tag_replacement is NULL
		 * 		   SUCCESS everything went well, src contains the
		 */
	int replace(const char *src, char *new_src, const char *tag, const char *tag_replacement){

		if (src, new_src, tag, tag_replacement == NULL) {
			return INVALID_NULL_PTR_DETECTED;
		}

		int src_len = strlen(src);
		int newsrc_len = strlen(new_src);
		int tag_len = strlen(tag);
		int rtag_len = strlen(tag_replacement);


		int i = 0;
		int change = 0;
		int delta = 0;
		while (i < src_len){
			if(*(src+i) == tag[0]) {
				if (strncmp((src + i), tag, tag_len) == 0) {

					for (int j = 0; j < rtag_len; j++) {
						*((new_src + i) + j) = *(tag_replacement + j);
					}
					change += rtag_len;
					delta += tag_len;
				}
			}
			*((new_src + i) + change) = *((src + i) + delta);
			i++;
		}
		return SUCCESS;
	}

	/**
		 * how often does the string in tag occur in src?
		 *
		 * \param src  initial char string
		 * \param tag  the tag to search for
		 * \return INVALID_NULL_PTR_DETECTED one or more of src, or tag is NULL
		 *         otherwise the number of times tag occurs in src
		 */
	int findNumbOccurrences(const char *src,  const char *tag) {
		if (src, tag == NULL) {
					return INVALID_NULL_PTR_DETECTED;
				}

		int lenSrc = strlen(src);
		int lenTag = strlen(tag);
		char *&pIter = src;
		int count = 0;

		for (int i = 0; i < lenSrc; i++) {
				//zoom along till we find the first char
				if (*(pIter + i) == tag[0]) {
					//found an a, lets see if it could be the start of a beautiful thing
					if (strncmp((pIter + i), tag, lenTag) == 0) {
						//got it whohoo, now what?
						cout << "Found \'"<<tag<<"\' in \'" << pIter << "\'" << endl;
						count++;
					}
				}
			}
		return count;
	}
}
