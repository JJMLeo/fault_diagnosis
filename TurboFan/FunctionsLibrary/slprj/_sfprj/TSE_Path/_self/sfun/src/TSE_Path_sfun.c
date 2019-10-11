/* Include files */

#include "TSE_Path_sfun.h"
#include "TSE_Path_sfun_debug_macros.h"
#include "c1_TSE_Path.h"
#include "c6_TSE_Path.h"
#include "c7_TSE_Path.h"
#include "c8_TSE_Path.h"
#include "c9_TSE_Path.h"
#include "c15_TSE_Path.h"
#include "c61_TSE_Path.h"
#include "c62_TSE_Path.h"
#include "c63_TSE_Path.h"
#include "c82_TSE_Path.h"
#include "c83_TSE_Path.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _TSE_PathMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void TSE_Path_initializer(void)
{
}

void TSE_Path_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_TSE_Path_method_dispatcher(SimStruct *simstructPtr, unsigned int
  chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_TSE_Path_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_TSE_Path_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_TSE_Path_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_TSE_Path_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_TSE_Path_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_TSE_Path_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==61) {
    c61_TSE_Path_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==62) {
    c62_TSE_Path_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==63) {
    c63_TSE_Path_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==82) {
    c82_TSE_Path_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==83) {
    c83_TSE_Path_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

extern void sf_TSE_Path_uses_exported_functions(int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_TSE_Path_process_check_sum_call( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4019114400U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1875867660U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(134007654U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4199925894U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2768270650U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3151053946U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(334316061U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(456736183U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_TSE_Path_get_check_sum(mxArray *plhs[]);
          sf_c1_TSE_Path_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_TSE_Path_get_check_sum(mxArray *plhs[]);
          sf_c6_TSE_Path_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_TSE_Path_get_check_sum(mxArray *plhs[]);
          sf_c7_TSE_Path_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_TSE_Path_get_check_sum(mxArray *plhs[]);
          sf_c8_TSE_Path_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_TSE_Path_get_check_sum(mxArray *plhs[]);
          sf_c9_TSE_Path_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_TSE_Path_get_check_sum(mxArray *plhs[]);
          sf_c15_TSE_Path_get_check_sum(plhs);
          break;
        }

       case 61:
        {
          extern void sf_c61_TSE_Path_get_check_sum(mxArray *plhs[]);
          sf_c61_TSE_Path_get_check_sum(plhs);
          break;
        }

       case 62:
        {
          extern void sf_c62_TSE_Path_get_check_sum(mxArray *plhs[]);
          sf_c62_TSE_Path_get_check_sum(plhs);
          break;
        }

       case 63:
        {
          extern void sf_c63_TSE_Path_get_check_sum(mxArray *plhs[]);
          sf_c63_TSE_Path_get_check_sum(plhs);
          break;
        }

       case 82:
        {
          extern void sf_c82_TSE_Path_get_check_sum(mxArray *plhs[]);
          sf_c82_TSE_Path_get_check_sum(plhs);
          break;
        }

       case 83:
        {
          extern void sf_c83_TSE_Path_get_check_sum(mxArray *plhs[]);
          sf_c83_TSE_Path_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1964399213U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4001958385U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1439661875U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1586612066U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_TSE_Path_autoinheritance_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
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
        if (strcmp(aiChksum, "Dej3tAgR1hQTul8cM7IDp") == 0) {
          extern mxArray *sf_c1_TSE_Path_get_autoinheritance_info(void);
          plhs[0] = sf_c1_TSE_Path_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "1RIb79VzhEHG1Am7puFPkD") == 0) {
          extern mxArray *sf_c6_TSE_Path_get_autoinheritance_info(void);
          plhs[0] = sf_c6_TSE_Path_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "QjFU8vDFYs5UQgzVGAOSH") == 0) {
          extern mxArray *sf_c7_TSE_Path_get_autoinheritance_info(void);
          plhs[0] = sf_c7_TSE_Path_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "nsUfoqClNxE6WnCsqKRkDB") == 0) {
          extern mxArray *sf_c8_TSE_Path_get_autoinheritance_info(void);
          plhs[0] = sf_c8_TSE_Path_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "cDo6fX2HBRnWytZMnN04VB") == 0) {
          extern mxArray *sf_c9_TSE_Path_get_autoinheritance_info(void);
          plhs[0] = sf_c9_TSE_Path_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "LYu61WbRzD9MXsq3T1doMB") == 0) {
          extern mxArray *sf_c15_TSE_Path_get_autoinheritance_info(void);
          plhs[0] = sf_c15_TSE_Path_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 61:
      {
        if (strcmp(aiChksum, "WcEdgJ4jcUBjZhkySBtuwG") == 0) {
          extern mxArray *sf_c61_TSE_Path_get_autoinheritance_info(void);
          plhs[0] = sf_c61_TSE_Path_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 62:
      {
        if (strcmp(aiChksum, "QoSao2dfJq5kz6XTKtPjF") == 0) {
          extern mxArray *sf_c62_TSE_Path_get_autoinheritance_info(void);
          plhs[0] = sf_c62_TSE_Path_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 63:
      {
        if (strcmp(aiChksum, "ZgpheNPTAWcZuDNerNmFdF") == 0) {
          extern mxArray *sf_c63_TSE_Path_get_autoinheritance_info(void);
          plhs[0] = sf_c63_TSE_Path_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 82:
      {
        if (strcmp(aiChksum, "NSNmGfQ1DH2JrqTttcj89B") == 0) {
          extern mxArray *sf_c82_TSE_Path_get_autoinheritance_info(void);
          plhs[0] = sf_c82_TSE_Path_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 83:
      {
        if (strcmp(aiChksum, "jCZXtIW0XW8w55lNZ2gpGG") == 0) {
          extern mxArray *sf_c83_TSE_Path_get_autoinheritance_info(void);
          plhs[0] = sf_c83_TSE_Path_get_autoinheritance_info();
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

unsigned int sf_TSE_Path_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
        extern const mxArray *sf_c1_TSE_Path_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_TSE_Path_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray *sf_c6_TSE_Path_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_TSE_Path_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray *sf_c7_TSE_Path_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_TSE_Path_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray *sf_c8_TSE_Path_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_TSE_Path_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray *sf_c9_TSE_Path_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_TSE_Path_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray *sf_c15_TSE_Path_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_TSE_Path_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 61:
      {
        extern const mxArray *sf_c61_TSE_Path_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c61_TSE_Path_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 62:
      {
        extern const mxArray *sf_c62_TSE_Path_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c62_TSE_Path_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 63:
      {
        extern const mxArray *sf_c63_TSE_Path_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c63_TSE_Path_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 82:
      {
        extern const mxArray *sf_c82_TSE_Path_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c82_TSE_Path_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 83:
      {
        extern const mxArray *sf_c83_TSE_Path_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c83_TSE_Path_get_eml_resolved_functions_info();
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

unsigned int sf_TSE_Path_third_party_uses_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
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
        if (strcmp(tpChksum, "JGXdQ6ZDh8xVfw6054JVCH") == 0) {
          extern mxArray *sf_c1_TSE_Path_third_party_uses_info(void);
          plhs[0] = sf_c1_TSE_Path_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "U6i44rTG2qq5GR0eX6TWkD") == 0) {
          extern mxArray *sf_c6_TSE_Path_third_party_uses_info(void);
          plhs[0] = sf_c6_TSE_Path_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "lMGTWVt3bHZgPWAApz7RfE") == 0) {
          extern mxArray *sf_c7_TSE_Path_third_party_uses_info(void);
          plhs[0] = sf_c7_TSE_Path_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "snyjHvgTtzynbSEr1k5Qq") == 0) {
          extern mxArray *sf_c8_TSE_Path_third_party_uses_info(void);
          plhs[0] = sf_c8_TSE_Path_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "eLXBfBtHeyDWfAO1fzyGlF") == 0) {
          extern mxArray *sf_c9_TSE_Path_third_party_uses_info(void);
          plhs[0] = sf_c9_TSE_Path_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "vGmD5v2x6AuLNhWuj04QKC") == 0) {
          extern mxArray *sf_c15_TSE_Path_third_party_uses_info(void);
          plhs[0] = sf_c15_TSE_Path_third_party_uses_info();
          break;
        }
      }

     case 61:
      {
        if (strcmp(tpChksum, "jbOjt0XXNdx2cZujOSqImC") == 0) {
          extern mxArray *sf_c61_TSE_Path_third_party_uses_info(void);
          plhs[0] = sf_c61_TSE_Path_third_party_uses_info();
          break;
        }
      }

     case 62:
      {
        if (strcmp(tpChksum, "GFeHpdeuasEDXOMNzVxrLC") == 0) {
          extern mxArray *sf_c62_TSE_Path_third_party_uses_info(void);
          plhs[0] = sf_c62_TSE_Path_third_party_uses_info();
          break;
        }
      }

     case 63:
      {
        if (strcmp(tpChksum, "6zDTO5L298G7N0BiVnhwHF") == 0) {
          extern mxArray *sf_c63_TSE_Path_third_party_uses_info(void);
          plhs[0] = sf_c63_TSE_Path_third_party_uses_info();
          break;
        }
      }

     case 82:
      {
        if (strcmp(tpChksum, "UIXErCqnzOGqZwmMsbSFpC") == 0) {
          extern mxArray *sf_c82_TSE_Path_third_party_uses_info(void);
          plhs[0] = sf_c82_TSE_Path_third_party_uses_info();
          break;
        }
      }

     case 83:
      {
        if (strcmp(tpChksum, "xRa3n1M84clqWxBr3ht0MG") == 0) {
          extern mxArray *sf_c83_TSE_Path_third_party_uses_info(void);
          plhs[0] = sf_c83_TSE_Path_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_TSE_Path_jit_fallback_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
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
        if (strcmp(tpChksum, "JGXdQ6ZDh8xVfw6054JVCH") == 0) {
          extern mxArray *sf_c1_TSE_Path_jit_fallback_info(void);
          plhs[0] = sf_c1_TSE_Path_jit_fallback_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "U6i44rTG2qq5GR0eX6TWkD") == 0) {
          extern mxArray *sf_c6_TSE_Path_jit_fallback_info(void);
          plhs[0] = sf_c6_TSE_Path_jit_fallback_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "lMGTWVt3bHZgPWAApz7RfE") == 0) {
          extern mxArray *sf_c7_TSE_Path_jit_fallback_info(void);
          plhs[0] = sf_c7_TSE_Path_jit_fallback_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "snyjHvgTtzynbSEr1k5Qq") == 0) {
          extern mxArray *sf_c8_TSE_Path_jit_fallback_info(void);
          plhs[0] = sf_c8_TSE_Path_jit_fallback_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "eLXBfBtHeyDWfAO1fzyGlF") == 0) {
          extern mxArray *sf_c9_TSE_Path_jit_fallback_info(void);
          plhs[0] = sf_c9_TSE_Path_jit_fallback_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "vGmD5v2x6AuLNhWuj04QKC") == 0) {
          extern mxArray *sf_c15_TSE_Path_jit_fallback_info(void);
          plhs[0] = sf_c15_TSE_Path_jit_fallback_info();
          break;
        }
      }

     case 61:
      {
        if (strcmp(tpChksum, "jbOjt0XXNdx2cZujOSqImC") == 0) {
          extern mxArray *sf_c61_TSE_Path_jit_fallback_info(void);
          plhs[0] = sf_c61_TSE_Path_jit_fallback_info();
          break;
        }
      }

     case 62:
      {
        if (strcmp(tpChksum, "GFeHpdeuasEDXOMNzVxrLC") == 0) {
          extern mxArray *sf_c62_TSE_Path_jit_fallback_info(void);
          plhs[0] = sf_c62_TSE_Path_jit_fallback_info();
          break;
        }
      }

     case 63:
      {
        if (strcmp(tpChksum, "6zDTO5L298G7N0BiVnhwHF") == 0) {
          extern mxArray *sf_c63_TSE_Path_jit_fallback_info(void);
          plhs[0] = sf_c63_TSE_Path_jit_fallback_info();
          break;
        }
      }

     case 82:
      {
        if (strcmp(tpChksum, "UIXErCqnzOGqZwmMsbSFpC") == 0) {
          extern mxArray *sf_c82_TSE_Path_jit_fallback_info(void);
          plhs[0] = sf_c82_TSE_Path_jit_fallback_info();
          break;
        }
      }

     case 83:
      {
        if (strcmp(tpChksum, "xRa3n1M84clqWxBr3ht0MG") == 0) {
          extern mxArray *sf_c83_TSE_Path_jit_fallback_info(void);
          plhs[0] = sf_c83_TSE_Path_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_TSE_Path_updateBuildInfo_args_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
        if (strcmp(tpChksum, "JGXdQ6ZDh8xVfw6054JVCH") == 0) {
          extern mxArray *sf_c1_TSE_Path_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_TSE_Path_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "U6i44rTG2qq5GR0eX6TWkD") == 0) {
          extern mxArray *sf_c6_TSE_Path_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_TSE_Path_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "lMGTWVt3bHZgPWAApz7RfE") == 0) {
          extern mxArray *sf_c7_TSE_Path_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_TSE_Path_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "snyjHvgTtzynbSEr1k5Qq") == 0) {
          extern mxArray *sf_c8_TSE_Path_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_TSE_Path_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "eLXBfBtHeyDWfAO1fzyGlF") == 0) {
          extern mxArray *sf_c9_TSE_Path_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_TSE_Path_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "vGmD5v2x6AuLNhWuj04QKC") == 0) {
          extern mxArray *sf_c15_TSE_Path_updateBuildInfo_args_info(void);
          plhs[0] = sf_c15_TSE_Path_updateBuildInfo_args_info();
          break;
        }
      }

     case 61:
      {
        if (strcmp(tpChksum, "jbOjt0XXNdx2cZujOSqImC") == 0) {
          extern mxArray *sf_c61_TSE_Path_updateBuildInfo_args_info(void);
          plhs[0] = sf_c61_TSE_Path_updateBuildInfo_args_info();
          break;
        }
      }

     case 62:
      {
        if (strcmp(tpChksum, "GFeHpdeuasEDXOMNzVxrLC") == 0) {
          extern mxArray *sf_c62_TSE_Path_updateBuildInfo_args_info(void);
          plhs[0] = sf_c62_TSE_Path_updateBuildInfo_args_info();
          break;
        }
      }

     case 63:
      {
        if (strcmp(tpChksum, "6zDTO5L298G7N0BiVnhwHF") == 0) {
          extern mxArray *sf_c63_TSE_Path_updateBuildInfo_args_info(void);
          plhs[0] = sf_c63_TSE_Path_updateBuildInfo_args_info();
          break;
        }
      }

     case 82:
      {
        if (strcmp(tpChksum, "UIXErCqnzOGqZwmMsbSFpC") == 0) {
          extern mxArray *sf_c82_TSE_Path_updateBuildInfo_args_info(void);
          plhs[0] = sf_c82_TSE_Path_updateBuildInfo_args_info();
          break;
        }
      }

     case 83:
      {
        if (strcmp(tpChksum, "xRa3n1M84clqWxBr3ht0MG") == 0) {
          extern mxArray *sf_c83_TSE_Path_updateBuildInfo_args_info(void);
          plhs[0] = sf_c83_TSE_Path_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_TSE_Path_get_post_codegen_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 1:
    {
      if (strcmp(tpChksum, "JGXdQ6ZDh8xVfw6054JVCH") == 0) {
        extern mxArray *sf_c1_TSE_Path_get_post_codegen_info(void);
        plhs[0] = sf_c1_TSE_Path_get_post_codegen_info();
        return;
      }
    }
    break;

   case 6:
    {
      if (strcmp(tpChksum, "U6i44rTG2qq5GR0eX6TWkD") == 0) {
        extern mxArray *sf_c6_TSE_Path_get_post_codegen_info(void);
        plhs[0] = sf_c6_TSE_Path_get_post_codegen_info();
        return;
      }
    }
    break;

   case 7:
    {
      if (strcmp(tpChksum, "lMGTWVt3bHZgPWAApz7RfE") == 0) {
        extern mxArray *sf_c7_TSE_Path_get_post_codegen_info(void);
        plhs[0] = sf_c7_TSE_Path_get_post_codegen_info();
        return;
      }
    }
    break;

   case 8:
    {
      if (strcmp(tpChksum, "snyjHvgTtzynbSEr1k5Qq") == 0) {
        extern mxArray *sf_c8_TSE_Path_get_post_codegen_info(void);
        plhs[0] = sf_c8_TSE_Path_get_post_codegen_info();
        return;
      }
    }
    break;

   case 9:
    {
      if (strcmp(tpChksum, "eLXBfBtHeyDWfAO1fzyGlF") == 0) {
        extern mxArray *sf_c9_TSE_Path_get_post_codegen_info(void);
        plhs[0] = sf_c9_TSE_Path_get_post_codegen_info();
        return;
      }
    }
    break;

   case 15:
    {
      if (strcmp(tpChksum, "vGmD5v2x6AuLNhWuj04QKC") == 0) {
        extern mxArray *sf_c15_TSE_Path_get_post_codegen_info(void);
        plhs[0] = sf_c15_TSE_Path_get_post_codegen_info();
        return;
      }
    }
    break;

   case 61:
    {
      if (strcmp(tpChksum, "jbOjt0XXNdx2cZujOSqImC") == 0) {
        extern mxArray *sf_c61_TSE_Path_get_post_codegen_info(void);
        plhs[0] = sf_c61_TSE_Path_get_post_codegen_info();
        return;
      }
    }
    break;

   case 62:
    {
      if (strcmp(tpChksum, "GFeHpdeuasEDXOMNzVxrLC") == 0) {
        extern mxArray *sf_c62_TSE_Path_get_post_codegen_info(void);
        plhs[0] = sf_c62_TSE_Path_get_post_codegen_info();
        return;
      }
    }
    break;

   case 63:
    {
      if (strcmp(tpChksum, "6zDTO5L298G7N0BiVnhwHF") == 0) {
        extern mxArray *sf_c63_TSE_Path_get_post_codegen_info(void);
        plhs[0] = sf_c63_TSE_Path_get_post_codegen_info();
        return;
      }
    }
    break;

   case 82:
    {
      if (strcmp(tpChksum, "UIXErCqnzOGqZwmMsbSFpC") == 0) {
        extern mxArray *sf_c82_TSE_Path_get_post_codegen_info(void);
        plhs[0] = sf_c82_TSE_Path_get_post_codegen_info();
        return;
      }
    }
    break;

   case 83:
    {
      if (strcmp(tpChksum, "xRa3n1M84clqWxBr3ht0MG") == 0) {
        extern mxArray *sf_c83_TSE_Path_get_post_codegen_info(void);
        plhs[0] = sf_c83_TSE_Path_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void TSE_Path_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _TSE_PathMachineNumber_ = sf_debug_initialize_machine(debugInstance,"TSE_Path",
    "sfun",0,11,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_TSE_PathMachineNumber_,0,
    0);
  sf_debug_set_machine_data_thresholds(debugInstance,_TSE_PathMachineNumber_,0);
}

void TSE_Path_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_TSE_Path_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("TSE_Path",
      "TSE_Path");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_TSE_Path_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
