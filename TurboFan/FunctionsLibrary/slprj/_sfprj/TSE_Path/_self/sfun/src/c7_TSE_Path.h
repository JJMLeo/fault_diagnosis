#ifndef __c7_TSE_Path_h__
#define __c7_TSE_Path_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc7_TSE_PathInstanceStruct
#define typedef_SFc7_TSE_PathInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c7_sfEvent;
  boolean_T c7_isStable;
  boolean_T c7_doneDoubleBufferReInit;
  uint8_T c7_is_active_c7_TSE_Path;
  real_T *c7_Sfcn2;
  real_T *c7_T2s;
  real_T *c7_h2;
  real_T *c7_f;
} SFc7_TSE_PathInstanceStruct;

#endif                                 /*typedef_SFc7_TSE_PathInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c7_TSE_Path_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c7_TSE_Path_get_check_sum(mxArray *plhs[]);
extern void c7_TSE_Path_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
