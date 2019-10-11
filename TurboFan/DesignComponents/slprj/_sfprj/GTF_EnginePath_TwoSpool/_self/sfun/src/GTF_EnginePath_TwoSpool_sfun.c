/* Include files */

#include "GTF_EnginePath_TwoSpool_sfun.h"
#include "GTF_EnginePath_TwoSpool_sfun_debug_macros.h"
#include "c1_GTF_EnginePath_TwoSpool.h"
#include "c2_GTF_EnginePath_TwoSpool.h"
#include "c3_GTF_EnginePath_TwoSpool.h"
#include "c4_GTF_EnginePath_TwoSpool.h"
#include "c5_GTF_EnginePath_TwoSpool.h"
#include "c6_GTF_EnginePath_TwoSpool.h"
#include "c7_GTF_EnginePath_TwoSpool.h"
#include "c8_GTF_EnginePath_TwoSpool.h"
#include "c9_GTF_EnginePath_TwoSpool.h"
#include "c15_GTF_EnginePath_TwoSpool.h"
#include "c16_GTF_EnginePath_TwoSpool.h"
#include "c76_GTF_EnginePath_TwoSpool.h"
#include "c77_GTF_EnginePath_TwoSpool.h"
#include "c78_GTF_EnginePath_TwoSpool.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _GTF_EnginePath_TwoSpoolMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void GTF_EnginePath_TwoSpool_initializer(void)
{
}

void GTF_EnginePath_TwoSpool_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_GTF_EnginePath_TwoSpool_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_GTF_EnginePath_TwoSpool_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_GTF_EnginePath_TwoSpool_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_GTF_EnginePath_TwoSpool_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_GTF_EnginePath_TwoSpool_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_GTF_EnginePath_TwoSpool_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_GTF_EnginePath_TwoSpool_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_GTF_EnginePath_TwoSpool_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_GTF_EnginePath_TwoSpool_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_GTF_EnginePath_TwoSpool_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_GTF_EnginePath_TwoSpool_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_GTF_EnginePath_TwoSpool_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==76) {
    c76_GTF_EnginePath_TwoSpool_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==77) {
    c77_GTF_EnginePath_TwoSpool_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==78) {
    c78_GTF_EnginePath_TwoSpool_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

extern void sf_GTF_EnginePath_TwoSpool_uses_exported_functions(int nlhs, mxArray
  * plhs[], int nrhs, const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_GTF_EnginePath_TwoSpool_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1171144675U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4004049627U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2872027189U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1704581007U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2351741392U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3395779841U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2765007523U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3120458227U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *plhs[]);
          sf_c1_GTF_EnginePath_TwoSpool_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *plhs[]);
          sf_c2_GTF_EnginePath_TwoSpool_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *plhs[]);
          sf_c3_GTF_EnginePath_TwoSpool_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *plhs[]);
          sf_c4_GTF_EnginePath_TwoSpool_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *plhs[]);
          sf_c5_GTF_EnginePath_TwoSpool_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *plhs[]);
          sf_c6_GTF_EnginePath_TwoSpool_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *plhs[]);
          sf_c7_GTF_EnginePath_TwoSpool_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *plhs[]);
          sf_c8_GTF_EnginePath_TwoSpool_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *plhs[]);
          sf_c9_GTF_EnginePath_TwoSpool_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *
            plhs[]);
          sf_c15_GTF_EnginePath_TwoSpool_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *
            plhs[]);
          sf_c16_GTF_EnginePath_TwoSpool_get_check_sum(plhs);
          break;
        }

       case 76:
        {
          extern void sf_c76_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *
            plhs[]);
          sf_c76_GTF_EnginePath_TwoSpool_get_check_sum(plhs);
          break;
        }

       case 77:
        {
          extern void sf_c77_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *
            plhs[]);
          sf_c77_GTF_EnginePath_TwoSpool_get_check_sum(plhs);
          break;
        }

       case 78:
        {
          extern void sf_c78_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *
            plhs[]);
          sf_c78_GTF_EnginePath_TwoSpool_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3061339410U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1991824845U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3599338742U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2357874978U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2000019391U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2771827444U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3953418302U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2279972328U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_GTF_EnginePath_TwoSpool_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "che2Z6dFmytEbKiM1ClTYH") == 0) {
          extern mxArray *sf_c1_GTF_EnginePath_TwoSpool_get_autoinheritance_info
            (void);
          plhs[0] = sf_c1_GTF_EnginePath_TwoSpool_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "4aZHVf2uu1AqZ1KNe1ZiaC") == 0) {
          extern mxArray *sf_c2_GTF_EnginePath_TwoSpool_get_autoinheritance_info
            (void);
          plhs[0] = sf_c2_GTF_EnginePath_TwoSpool_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "M8bLvTMEG2z4hvz06eZVvG") == 0) {
          extern mxArray *sf_c3_GTF_EnginePath_TwoSpool_get_autoinheritance_info
            (void);
          plhs[0] = sf_c3_GTF_EnginePath_TwoSpool_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "sgdZujAwLSjeDG5fINtgLC") == 0) {
          extern mxArray *sf_c4_GTF_EnginePath_TwoSpool_get_autoinheritance_info
            (void);
          plhs[0] = sf_c4_GTF_EnginePath_TwoSpool_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "A6DBJ7aBqjGTcKQ6s2AqeD") == 0) {
          extern mxArray *sf_c5_GTF_EnginePath_TwoSpool_get_autoinheritance_info
            (void);
          plhs[0] = sf_c5_GTF_EnginePath_TwoSpool_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "px2tW36DATqWnr88Qw2k") == 0) {
          extern mxArray *sf_c6_GTF_EnginePath_TwoSpool_get_autoinheritance_info
            (void);
          plhs[0] = sf_c6_GTF_EnginePath_TwoSpool_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "PQPrrFnXV3h60zVLdfp0qE") == 0) {
          extern mxArray *sf_c7_GTF_EnginePath_TwoSpool_get_autoinheritance_info
            (void);
          plhs[0] = sf_c7_GTF_EnginePath_TwoSpool_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "gvn6DN7SVva4PlLiKZrOIB") == 0) {
          extern mxArray *sf_c8_GTF_EnginePath_TwoSpool_get_autoinheritance_info
            (void);
          plhs[0] = sf_c8_GTF_EnginePath_TwoSpool_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "eCMpWrhcnvo8ro34T16YtD") == 0) {
          extern mxArray *sf_c9_GTF_EnginePath_TwoSpool_get_autoinheritance_info
            (void);
          plhs[0] = sf_c9_GTF_EnginePath_TwoSpool_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "8ye2MZWnzKz9SVUznogUUF") == 0) {
          extern mxArray
            *sf_c15_GTF_EnginePath_TwoSpool_get_autoinheritance_info(void);
          plhs[0] = sf_c15_GTF_EnginePath_TwoSpool_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 16:
      {
        if (strcmp(aiChksum, "ndtJuwrM91mDJr32tERleH") == 0) {
          extern mxArray
            *sf_c16_GTF_EnginePath_TwoSpool_get_autoinheritance_info(void);
          plhs[0] = sf_c16_GTF_EnginePath_TwoSpool_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 76:
      {
        if (strcmp(aiChksum, "89GPRxRaJOzs4VqzWSyqNH") == 0) {
          extern mxArray
            *sf_c76_GTF_EnginePath_TwoSpool_get_autoinheritance_info(void);
          plhs[0] = sf_c76_GTF_EnginePath_TwoSpool_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 77:
      {
        if (strcmp(aiChksum, "VYeynDL67yF22YLcWPLlrG") == 0) {
          extern mxArray
            *sf_c77_GTF_EnginePath_TwoSpool_get_autoinheritance_info(void);
          plhs[0] = sf_c77_GTF_EnginePath_TwoSpool_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 78:
      {
        if (strcmp(aiChksum, "r7Q7QBeoAbhnUwyoYGn5cF") == 0) {
          extern mxArray
            *sf_c78_GTF_EnginePath_TwoSpool_get_autoinheritance_info(void);
          plhs[0] = sf_c78_GTF_EnginePath_TwoSpool_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray
          *sf_c16_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 76:
      {
        extern const mxArray
          *sf_c76_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c76_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 77:
      {
        extern const mxArray
          *sf_c77_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c77_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 78:
      {
        extern const mxArray
          *sf_c78_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c78_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_GTF_EnginePath_TwoSpool_third_party_uses_info( int nlhs, mxArray
  * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "eY93IdjmuFV3VxBjNSVl1") == 0) {
          extern mxArray *sf_c1_GTF_EnginePath_TwoSpool_third_party_uses_info
            (void);
          plhs[0] = sf_c1_GTF_EnginePath_TwoSpool_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "PHrdnWbGsbzYAsvt1W0pIB") == 0) {
          extern mxArray *sf_c2_GTF_EnginePath_TwoSpool_third_party_uses_info
            (void);
          plhs[0] = sf_c2_GTF_EnginePath_TwoSpool_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "hY6N5QwD64f0xYl9kmMQSB") == 0) {
          extern mxArray *sf_c3_GTF_EnginePath_TwoSpool_third_party_uses_info
            (void);
          plhs[0] = sf_c3_GTF_EnginePath_TwoSpool_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "S7OjRIZ0Ko5SJHxAo1CyAF") == 0) {
          extern mxArray *sf_c4_GTF_EnginePath_TwoSpool_third_party_uses_info
            (void);
          plhs[0] = sf_c4_GTF_EnginePath_TwoSpool_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "BMpZ6dlflB2UoXEt6xzzWE") == 0) {
          extern mxArray *sf_c5_GTF_EnginePath_TwoSpool_third_party_uses_info
            (void);
          plhs[0] = sf_c5_GTF_EnginePath_TwoSpool_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "YEXsXM9KJPFujDB06WQoc") == 0) {
          extern mxArray *sf_c6_GTF_EnginePath_TwoSpool_third_party_uses_info
            (void);
          plhs[0] = sf_c6_GTF_EnginePath_TwoSpool_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "4y9hIxj2wzQm53t7KN8VkE") == 0) {
          extern mxArray *sf_c7_GTF_EnginePath_TwoSpool_third_party_uses_info
            (void);
          plhs[0] = sf_c7_GTF_EnginePath_TwoSpool_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "7wp3dj1vOEfCQgYOo7FDWE") == 0) {
          extern mxArray *sf_c8_GTF_EnginePath_TwoSpool_third_party_uses_info
            (void);
          plhs[0] = sf_c8_GTF_EnginePath_TwoSpool_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "RpCGjcwyNdicEAY4eUDmaE") == 0) {
          extern mxArray *sf_c9_GTF_EnginePath_TwoSpool_third_party_uses_info
            (void);
          plhs[0] = sf_c9_GTF_EnginePath_TwoSpool_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "r18kPKExUx3KAHhD1j5spB") == 0) {
          extern mxArray *sf_c15_GTF_EnginePath_TwoSpool_third_party_uses_info
            (void);
          plhs[0] = sf_c15_GTF_EnginePath_TwoSpool_third_party_uses_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "D4kpZ8WzBs3pEy9EEfFY3F") == 0) {
          extern mxArray *sf_c16_GTF_EnginePath_TwoSpool_third_party_uses_info
            (void);
          plhs[0] = sf_c16_GTF_EnginePath_TwoSpool_third_party_uses_info();
          break;
        }
      }

     case 76:
      {
        if (strcmp(tpChksum, "EjXguKOIBZucSwWdPb1MAD") == 0) {
          extern mxArray *sf_c76_GTF_EnginePath_TwoSpool_third_party_uses_info
            (void);
          plhs[0] = sf_c76_GTF_EnginePath_TwoSpool_third_party_uses_info();
          break;
        }
      }

     case 77:
      {
        if (strcmp(tpChksum, "TuqNE18OPirDPClrXN7H7") == 0) {
          extern mxArray *sf_c77_GTF_EnginePath_TwoSpool_third_party_uses_info
            (void);
          plhs[0] = sf_c77_GTF_EnginePath_TwoSpool_third_party_uses_info();
          break;
        }
      }

     case 78:
      {
        if (strcmp(tpChksum, "81KfiZYG0q8gp7MdqiZu5G") == 0) {
          extern mxArray *sf_c78_GTF_EnginePath_TwoSpool_third_party_uses_info
            (void);
          plhs[0] = sf_c78_GTF_EnginePath_TwoSpool_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_GTF_EnginePath_TwoSpool_jit_fallback_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the jit_fallback_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_jit_fallback_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "eY93IdjmuFV3VxBjNSVl1") == 0) {
          extern mxArray *sf_c1_GTF_EnginePath_TwoSpool_jit_fallback_info(void);
          plhs[0] = sf_c1_GTF_EnginePath_TwoSpool_jit_fallback_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "PHrdnWbGsbzYAsvt1W0pIB") == 0) {
          extern mxArray *sf_c2_GTF_EnginePath_TwoSpool_jit_fallback_info(void);
          plhs[0] = sf_c2_GTF_EnginePath_TwoSpool_jit_fallback_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "hY6N5QwD64f0xYl9kmMQSB") == 0) {
          extern mxArray *sf_c3_GTF_EnginePath_TwoSpool_jit_fallback_info(void);
          plhs[0] = sf_c3_GTF_EnginePath_TwoSpool_jit_fallback_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "S7OjRIZ0Ko5SJHxAo1CyAF") == 0) {
          extern mxArray *sf_c4_GTF_EnginePath_TwoSpool_jit_fallback_info(void);
          plhs[0] = sf_c4_GTF_EnginePath_TwoSpool_jit_fallback_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "BMpZ6dlflB2UoXEt6xzzWE") == 0) {
          extern mxArray *sf_c5_GTF_EnginePath_TwoSpool_jit_fallback_info(void);
          plhs[0] = sf_c5_GTF_EnginePath_TwoSpool_jit_fallback_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "YEXsXM9KJPFujDB06WQoc") == 0) {
          extern mxArray *sf_c6_GTF_EnginePath_TwoSpool_jit_fallback_info(void);
          plhs[0] = sf_c6_GTF_EnginePath_TwoSpool_jit_fallback_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "4y9hIxj2wzQm53t7KN8VkE") == 0) {
          extern mxArray *sf_c7_GTF_EnginePath_TwoSpool_jit_fallback_info(void);
          plhs[0] = sf_c7_GTF_EnginePath_TwoSpool_jit_fallback_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "7wp3dj1vOEfCQgYOo7FDWE") == 0) {
          extern mxArray *sf_c8_GTF_EnginePath_TwoSpool_jit_fallback_info(void);
          plhs[0] = sf_c8_GTF_EnginePath_TwoSpool_jit_fallback_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "RpCGjcwyNdicEAY4eUDmaE") == 0) {
          extern mxArray *sf_c9_GTF_EnginePath_TwoSpool_jit_fallback_info(void);
          plhs[0] = sf_c9_GTF_EnginePath_TwoSpool_jit_fallback_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "r18kPKExUx3KAHhD1j5spB") == 0) {
          extern mxArray *sf_c15_GTF_EnginePath_TwoSpool_jit_fallback_info(void);
          plhs[0] = sf_c15_GTF_EnginePath_TwoSpool_jit_fallback_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "D4kpZ8WzBs3pEy9EEfFY3F") == 0) {
          extern mxArray *sf_c16_GTF_EnginePath_TwoSpool_jit_fallback_info(void);
          plhs[0] = sf_c16_GTF_EnginePath_TwoSpool_jit_fallback_info();
          break;
        }
      }

     case 76:
      {
        if (strcmp(tpChksum, "EjXguKOIBZucSwWdPb1MAD") == 0) {
          extern mxArray *sf_c76_GTF_EnginePath_TwoSpool_jit_fallback_info(void);
          plhs[0] = sf_c76_GTF_EnginePath_TwoSpool_jit_fallback_info();
          break;
        }
      }

     case 77:
      {
        if (strcmp(tpChksum, "TuqNE18OPirDPClrXN7H7") == 0) {
          extern mxArray *sf_c77_GTF_EnginePath_TwoSpool_jit_fallback_info(void);
          plhs[0] = sf_c77_GTF_EnginePath_TwoSpool_jit_fallback_info();
          break;
        }
      }

     case 78:
      {
        if (strcmp(tpChksum, "81KfiZYG0q8gp7MdqiZu5G") == 0) {
          extern mxArray *sf_c78_GTF_EnginePath_TwoSpool_jit_fallback_info(void);
          plhs[0] = sf_c78_GTF_EnginePath_TwoSpool_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "eY93IdjmuFV3VxBjNSVl1") == 0) {
          extern mxArray
            *sf_c1_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "PHrdnWbGsbzYAsvt1W0pIB") == 0) {
          extern mxArray
            *sf_c2_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "hY6N5QwD64f0xYl9kmMQSB") == 0) {
          extern mxArray
            *sf_c3_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "S7OjRIZ0Ko5SJHxAo1CyAF") == 0) {
          extern mxArray
            *sf_c4_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "BMpZ6dlflB2UoXEt6xzzWE") == 0) {
          extern mxArray
            *sf_c5_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "YEXsXM9KJPFujDB06WQoc") == 0) {
          extern mxArray
            *sf_c6_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "4y9hIxj2wzQm53t7KN8VkE") == 0) {
          extern mxArray
            *sf_c7_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "7wp3dj1vOEfCQgYOo7FDWE") == 0) {
          extern mxArray
            *sf_c8_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "RpCGjcwyNdicEAY4eUDmaE") == 0) {
          extern mxArray
            *sf_c9_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "r18kPKExUx3KAHhD1j5spB") == 0) {
          extern mxArray
            *sf_c15_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info(void);
          plhs[0] = sf_c15_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "D4kpZ8WzBs3pEy9EEfFY3F") == 0) {
          extern mxArray
            *sf_c16_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info(void);
          plhs[0] = sf_c16_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info();
          break;
        }
      }

     case 76:
      {
        if (strcmp(tpChksum, "EjXguKOIBZucSwWdPb1MAD") == 0) {
          extern mxArray
            *sf_c76_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info(void);
          plhs[0] = sf_c76_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info();
          break;
        }
      }

     case 77:
      {
        if (strcmp(tpChksum, "TuqNE18OPirDPClrXN7H7") == 0) {
          extern mxArray
            *sf_c77_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info(void);
          plhs[0] = sf_c77_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info();
          break;
        }
      }

     case 78:
      {
        if (strcmp(tpChksum, "81KfiZYG0q8gp7MdqiZu5G") == 0) {
          extern mxArray
            *sf_c78_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info(void);
          plhs[0] = sf_c78_GTF_EnginePath_TwoSpool_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_GTF_EnginePath_TwoSpool_get_post_codegen_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 1:
    {
      if (strcmp(tpChksum, "eY93IdjmuFV3VxBjNSVl1") == 0) {
        extern mxArray *sf_c1_GTF_EnginePath_TwoSpool_get_post_codegen_info(void);
        plhs[0] = sf_c1_GTF_EnginePath_TwoSpool_get_post_codegen_info();
        return;
      }
    }
    break;

   case 2:
    {
      if (strcmp(tpChksum, "PHrdnWbGsbzYAsvt1W0pIB") == 0) {
        extern mxArray *sf_c2_GTF_EnginePath_TwoSpool_get_post_codegen_info(void);
        plhs[0] = sf_c2_GTF_EnginePath_TwoSpool_get_post_codegen_info();
        return;
      }
    }
    break;

   case 3:
    {
      if (strcmp(tpChksum, "hY6N5QwD64f0xYl9kmMQSB") == 0) {
        extern mxArray *sf_c3_GTF_EnginePath_TwoSpool_get_post_codegen_info(void);
        plhs[0] = sf_c3_GTF_EnginePath_TwoSpool_get_post_codegen_info();
        return;
      }
    }
    break;

   case 4:
    {
      if (strcmp(tpChksum, "S7OjRIZ0Ko5SJHxAo1CyAF") == 0) {
        extern mxArray *sf_c4_GTF_EnginePath_TwoSpool_get_post_codegen_info(void);
        plhs[0] = sf_c4_GTF_EnginePath_TwoSpool_get_post_codegen_info();
        return;
      }
    }
    break;

   case 5:
    {
      if (strcmp(tpChksum, "BMpZ6dlflB2UoXEt6xzzWE") == 0) {
        extern mxArray *sf_c5_GTF_EnginePath_TwoSpool_get_post_codegen_info(void);
        plhs[0] = sf_c5_GTF_EnginePath_TwoSpool_get_post_codegen_info();
        return;
      }
    }
    break;

   case 6:
    {
      if (strcmp(tpChksum, "YEXsXM9KJPFujDB06WQoc") == 0) {
        extern mxArray *sf_c6_GTF_EnginePath_TwoSpool_get_post_codegen_info(void);
        plhs[0] = sf_c6_GTF_EnginePath_TwoSpool_get_post_codegen_info();
        return;
      }
    }
    break;

   case 7:
    {
      if (strcmp(tpChksum, "4y9hIxj2wzQm53t7KN8VkE") == 0) {
        extern mxArray *sf_c7_GTF_EnginePath_TwoSpool_get_post_codegen_info(void);
        plhs[0] = sf_c7_GTF_EnginePath_TwoSpool_get_post_codegen_info();
        return;
      }
    }
    break;

   case 8:
    {
      if (strcmp(tpChksum, "7wp3dj1vOEfCQgYOo7FDWE") == 0) {
        extern mxArray *sf_c8_GTF_EnginePath_TwoSpool_get_post_codegen_info(void);
        plhs[0] = sf_c8_GTF_EnginePath_TwoSpool_get_post_codegen_info();
        return;
      }
    }
    break;

   case 9:
    {
      if (strcmp(tpChksum, "RpCGjcwyNdicEAY4eUDmaE") == 0) {
        extern mxArray *sf_c9_GTF_EnginePath_TwoSpool_get_post_codegen_info(void);
        plhs[0] = sf_c9_GTF_EnginePath_TwoSpool_get_post_codegen_info();
        return;
      }
    }
    break;

   case 15:
    {
      if (strcmp(tpChksum, "r18kPKExUx3KAHhD1j5spB") == 0) {
        extern mxArray *sf_c15_GTF_EnginePath_TwoSpool_get_post_codegen_info
          (void);
        plhs[0] = sf_c15_GTF_EnginePath_TwoSpool_get_post_codegen_info();
        return;
      }
    }
    break;

   case 16:
    {
      if (strcmp(tpChksum, "D4kpZ8WzBs3pEy9EEfFY3F") == 0) {
        extern mxArray *sf_c16_GTF_EnginePath_TwoSpool_get_post_codegen_info
          (void);
        plhs[0] = sf_c16_GTF_EnginePath_TwoSpool_get_post_codegen_info();
        return;
      }
    }
    break;

   case 76:
    {
      if (strcmp(tpChksum, "EjXguKOIBZucSwWdPb1MAD") == 0) {
        extern mxArray *sf_c76_GTF_EnginePath_TwoSpool_get_post_codegen_info
          (void);
        plhs[0] = sf_c76_GTF_EnginePath_TwoSpool_get_post_codegen_info();
        return;
      }
    }
    break;

   case 77:
    {
      if (strcmp(tpChksum, "TuqNE18OPirDPClrXN7H7") == 0) {
        extern mxArray *sf_c77_GTF_EnginePath_TwoSpool_get_post_codegen_info
          (void);
        plhs[0] = sf_c77_GTF_EnginePath_TwoSpool_get_post_codegen_info();
        return;
      }
    }
    break;

   case 78:
    {
      if (strcmp(tpChksum, "81KfiZYG0q8gp7MdqiZu5G") == 0) {
        extern mxArray *sf_c78_GTF_EnginePath_TwoSpool_get_post_codegen_info
          (void);
        plhs[0] = sf_c78_GTF_EnginePath_TwoSpool_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void GTF_EnginePath_TwoSpool_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _GTF_EnginePath_TwoSpoolMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"GTF_EnginePath_TwoSpool","sfun",0,14,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _GTF_EnginePath_TwoSpoolMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _GTF_EnginePath_TwoSpoolMachineNumber_,0);
}

void GTF_EnginePath_TwoSpool_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_GTF_EnginePath_TwoSpool_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "GTF_EnginePath_TwoSpool", "GTF_EnginePath_TwoSpool");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_GTF_EnginePath_TwoSpool_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
