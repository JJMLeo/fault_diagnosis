#ifndef __c8_GTF_EnginePath_TwoSpool_h__
#define __c8_GTF_EnginePath_TwoSpool_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc8_GTF_EnginePath_TwoSpoolInstanceStruct
#define typedef_SFc8_GTF_EnginePath_TwoSpoolInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c8_sfEvent;
  boolean_T c8_isStable;
  boolean_T c8_doneDoubleBufferReInit;
  uint8_T c8_is_active_c8_GTF_EnginePath_TwoSpool;
  real_T *c8_W5;
  real_T *c8_Tt5;
  real_T *c8_WcoolLPT;
  real_T *c8_Tt_Z2;
  real_T *c8_Tt51;
  real_T *c8_W51;
  real_T *c8_Sfcn51;
  real_T *c8_Wf;
} SFc8_GTF_EnginePath_TwoSpoolInstanceStruct;

#endif                                 /*typedef_SFc8_GTF_EnginePath_TwoSpoolInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c8_GTF_EnginePath_TwoSpool_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c8_GTF_EnginePath_TwoSpool_get_check_sum(mxArray *plhs[]);
extern void c8_GTF_EnginePath_TwoSpool_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
