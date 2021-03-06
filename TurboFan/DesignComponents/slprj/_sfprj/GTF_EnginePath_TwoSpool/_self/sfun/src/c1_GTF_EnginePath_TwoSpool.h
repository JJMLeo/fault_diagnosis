#ifndef __c1_GTF_EnginePath_TwoSpool_h__
#define __c1_GTF_EnginePath_TwoSpool_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_GTF_EnginePath_TwoSpoolInstanceStruct
#define typedef_SFc1_GTF_EnginePath_TwoSpoolInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_isStable;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_GTF_EnginePath_TwoSpool;
  real_T *c1_h21;
  real_T *c1_h2;
  real_T *c1_PR;
  real_T *c1_Tt21;
  real_T *c1_Eff;
  real_T *c1_Tt2;
} SFc1_GTF_EnginePath_TwoSpoolInstanceStruct;

#endif                                 /*typedef_SFc1_GTF_EnginePath_TwoSpoolInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *plhs[]);
extern void c1_GTF_EnginePath_TwoSpool_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
