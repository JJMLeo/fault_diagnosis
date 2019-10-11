#ifndef __c2_GTF_EnginePath_TwoSpool_h__
#define __c2_GTF_EnginePath_TwoSpool_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_GTF_EnginePath_TwoSpoolInstanceStruct
#define typedef_SFc2_GTF_EnginePath_TwoSpoolInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_isStable;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_GTF_EnginePath_TwoSpool;
  real_T *c2_h13;
  real_T *c2_h2;
  real_T *c2_PR;
  real_T *c2_Tt13;
  real_T *c2_Eff;
  real_T *c2_Tt2;
} SFc2_GTF_EnginePath_TwoSpoolInstanceStruct;

#endif                                 /*typedef_SFc2_GTF_EnginePath_TwoSpoolInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c2_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *plhs[]);
extern void c2_GTF_EnginePath_TwoSpool_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
