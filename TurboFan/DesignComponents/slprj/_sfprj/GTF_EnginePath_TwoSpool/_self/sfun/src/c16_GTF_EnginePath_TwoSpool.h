#ifndef __c16_GTF_EnginePath_TwoSpool_h__
#define __c16_GTF_EnginePath_TwoSpool_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc16_GTF_EnginePath_TwoSpoolInstanceStruct
#define typedef_SFc16_GTF_EnginePath_TwoSpoolInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c16_sfEvent;
  boolean_T c16_isStable;
  boolean_T c16_doneDoubleBufferReInit;
  uint8_T c16_is_active_c16_GTF_EnginePath_TwoSpool;
  real_T *c16_Pt8;
  real_T *c16_Tt8;
  real_T *c16_Pt_in;
  real_T *c16_Tt_in;
  real_T *c16_W_in;
  real_T *c16_W8;
  real_T *c16_V;
  real_T *c16_Ma;
  real_T *c16_PR_Real;
  real_T *c16_Pamb;
  real_T *c16_Wf;
  real_T *c16_P8;
} SFc16_GTF_EnginePath_TwoSpoolInstanceStruct;

#endif                                 /*typedef_SFc16_GTF_EnginePath_TwoSpoolInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c16_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c16_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *plhs[]);
extern void c16_GTF_EnginePath_TwoSpool_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
