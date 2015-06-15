/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief includes of the new pages
 */
#ifndef _PAGES_H_
#define _PAGES_H_

#include "page0.h"
/* add here the header of the new page */

#ifdef __cplusplus
extern "C" {
#endif
int create_page_nb(page ** p, int pagenb);
#ifdef __cplusplus
}
#endif

#endif
