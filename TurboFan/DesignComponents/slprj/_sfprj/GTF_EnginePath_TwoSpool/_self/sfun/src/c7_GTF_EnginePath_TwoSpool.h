#ifndef __c7_GTF_EnginePath_TwoSpool_h__
#define __c7_GTF_EnginePath_TwoSpool_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc7_GTF_EnginePath_TwoSpoolInstanceStruct
#define typedef_SFc7_GTF_EnginePath_TwoSpoolInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c7_sfEvent;
  boolean_T c7_isStable;
  boolean_T c7_doneDoubleBufferReInit;
  uint8_T c7_is_active_c7_GTF_EnginePath_TwoSpool;
  real_T *c7_Tt44;
  real_T *c7_W44;
  real_T *c7_WcoolLPT;
  real_T *c7_Tt_Z3;
  real_T *c7_Tt45;
  real_T *c7_Wf;
  real_T *c7_Sfcn45;
} SFc7_GTF_EnginePath_TwoSpoolInstanceStruct;

#endif                                 /*typedef_SFc7_GTF_EnginePath_TwoSpoolInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c7_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c7_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *plhs[]);
extern void c7_GTF_EnginePath_TwoSpool_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
