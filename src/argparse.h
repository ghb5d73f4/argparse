/**
 -*- coding: utf-8 -*-
 -*- format: c++ -*-
 -*- file: argparse.h -*-
 -*- author: G.Henning -*-
 -*- copyright: GH / IPHC (2013) -*-
 -*- date:  Sept 26 2013 -*-
 -*- purpose: Parse arguments from command line -*-
**/

#ifndef ARGPARSE_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Prototypes */
const int ParseFlag(const int argc,
		    const char* argv[],
		    const char* flag);

const int ParseInt(const int argc,
		   const char* argv[],
		   const char* arg,
		   const int orelse);

const float ParseFloat(const int argc,
		       const char* argv[],
		       const char* arg,
		       const float orelse);

const char* ParseString(const int argc,
			const char* argv[],
			const char* arg,
			const char* orelse);
const int CountArgs(const int argc,
		    const char* argv[]);
const char **GetArgs(const int argc,
		     const char* argv[],
		     const int ArgCount);

#define ARGPARSE_H_
#endif

/** end of file **/