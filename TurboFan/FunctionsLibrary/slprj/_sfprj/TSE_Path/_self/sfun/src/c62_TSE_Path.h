#ifndef __c62_TSE_Path_h__
#define __c62_TSE_Path_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc62_TSE_PathInstanceStruct
#define typedef_SFc62_TSE_PathInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c62_sfEvent;
  boolean_T c62_isStable;
  boolean_T c62_doneDoubleBufferReInit;
  uint8_T c62_is_active_c62_TSE_Path;
  real_T *c62_T4s;
  real_T *c62_WG4;
  real_T *c62_WcoolGT;
  real_T *c62_T3s;
  real_T *c62_T4snew;
  real_T *c62_Wf;
  real_T *c62_Sfcn4new;
} SFc62_TSE_PathInstanceStruct;

#endif                                 /*typedef_SFc62_TSE_PathInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c62_TSE_Path_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c62_TSE_Path_get_check_sum(mxArray *plhs[]);
extern void c62_TSE_Path_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
