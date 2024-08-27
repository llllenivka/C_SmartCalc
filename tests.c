#include <check.h>

#include "s21_smart_calc.h"

/***********************************/
/*********** CORRECT_STR ***********/
/***********************************/

START_TEST(test_correct_str1) {
  char exprassion[100] = "2+1234";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  double check_result = 2 + 1234;
  int check_code = CODE_TRUE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
  ck_assert_double_eq_tol(result, check_result, 0.0000001);
}
END_TEST

START_TEST(test_correct_str2) {
  char exprassion[100] = "2-1234";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  double check_result = 2 - 1234;
  int check_code = CODE_TRUE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
  ck_assert_double_eq_tol(result, check_result, 1e-07);
}
END_TEST

START_TEST(test_correct_str3) {
  char exprassion[100] = "123/46";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  double check_result = 123.0 / 46.0;
  int check_code = CODE_TRUE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
  ck_assert_double_eq_tol(result, check_result, 1e-07);
}
END_TEST

START_TEST(test_correct_str4) {
  char exprassion[100] = "123.46*89.123";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  double check_result = 123.46 * 89.123;
  int check_code = CODE_TRUE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
  ck_assert_double_eq_tol(result, check_result, 1e-07);
}
END_TEST

START_TEST(test_correct_str5) {
  char exprassion[100] = "123.46^89.123";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  double check_result = pow(123.46, 89.123);
  int check_code = CODE_TRUE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
  ck_assert_double_eq_tol(result, check_result, 1e-07);
}
END_TEST

START_TEST(test_correct_str6) {
  char exprassion[100] = "12mod8";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  double check_result = fmod(12, 8);
  int check_code = CODE_TRUE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
  ck_assert_double_eq_tol(result, check_result, 1e-07);
}
END_TEST

START_TEST(test_correct_str7) {
  char exprassion[100] = "(12.6*12.3)";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  double check_result = (12.6 * 12.3);
  int check_code = CODE_TRUE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
  ck_assert_double_eq_tol(result, check_result, 1e-07);
}
END_TEST

START_TEST(test_correct_str8) {
  char exprassion[100] = "(1.12-3.23)/(12.0+12.0)";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  double check_result = (1.12 - 3.23) / (12.0 + 12.0);
  int check_code = CODE_TRUE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
  ck_assert_double_eq_tol(result, check_result, 1e-07);
}
END_TEST

START_TEST(test_correct_str9) {
  char exprassion[100] = "(1.12-3.23*0.1)/(12.0+12.0*0.1-1)";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  double check_result = 0.0653279;
  int check_code = CODE_TRUE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
  ck_assert_double_eq_tol(result, check_result, 1e-07);
}
END_TEST

START_TEST(test_correct_str10) {
  char exprassion[100] = "sin(12)";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  double check_result = sin(12);
  int check_code = CODE_TRUE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
  ck_assert_double_eq_tol(result, check_result, 1e-07);
}
END_TEST

START_TEST(test_correct_str11) {
  char exprassion[100] = "cos(1.1)";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  double check_result = cos(1.1);
  int check_code = CODE_TRUE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
  ck_assert_double_eq_tol(result, check_result, 1e-07);
}
END_TEST

START_TEST(test_correct_str12) {
  char exprassion[100] = "tan(11.1)";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  double check_result = tan(11.1);
  int check_code = CODE_TRUE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
  ck_assert_double_eq_tol(result, check_result, 1e-07);
}
END_TEST

START_TEST(test_correct_str13) {
  char exprassion[100] = "atan(11.1+1)";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  double check_result = atan(11.1 + 1);
  int check_code = CODE_TRUE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
  ck_assert_double_eq_tol(result, check_result, 1e-07);
}
END_TEST

START_TEST(test_correct_str14) {
  char exprassion[100] = "asin(0)";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  double check_result = asin(0);
  int check_code = CODE_TRUE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
  ck_assert_double_eq_tol(result, check_result, 1e-07);
}
END_TEST

START_TEST(test_correct_str15) {
  char exprassion[100] = "(-0.1+0.1)";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  double check_result = (-0.1 + 0.1);
  int check_code = CODE_TRUE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
  ck_assert_double_eq_tol(result, check_result, 1e-07);
}
END_TEST

START_TEST(test_correct_str16) {
  char exprassion[100] = "acos(1.2/2.0)";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  double check_result = acos(1.2 / 2.0);
  int check_code = CODE_TRUE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
  ck_assert_double_eq_tol(result, check_result, 1e-07);
}
END_TEST

START_TEST(test_correct_str17) {
  char exprassion[100] = "sqrt(134.5)";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  double check_result = sqrt(134.5);
  int check_code = CODE_TRUE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
  ck_assert_double_eq_tol(result, check_result, 1e-07);
}
END_TEST

START_TEST(test_correct_str18) {
  char exprassion[100] = "log(134.51)";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  double check_result = log10(134.51);
  int check_code = CODE_TRUE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
  ck_assert_double_eq_tol(result, check_result, 1e-07);
}
END_TEST

START_TEST(test_correct_str19) {
  char exprassion[100] = "ln(1.3*2.67)";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  double check_result = log(1.3 * 2.67);
  int check_code = CODE_TRUE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
  ck_assert_double_eq_tol(result, check_result, 1e-07);
}
END_TEST

START_TEST(test_correct_str20) {
  char exprassion[100] = "sin(12.99)*cos(23.4)";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  double check_result = sin(12.99) * cos(23.4);
  int check_code = CODE_TRUE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
  ck_assert_double_eq_tol(result, check_result, 1e-07);
}
END_TEST

START_TEST(test_correct_str21) {
  char exprassion[100] = "atan(123)-acos(-0.023)";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  double check_result = atan(123) - acos(-0.023);
  int check_code = CODE_TRUE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
  ck_assert_double_eq_tol(result, check_result, 1e-07);
}
END_TEST

START_TEST(test_correct_str22) {
  char exprassion[100] = "ln(21^34)";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  double check_result = log(pow(21, 34));
  int check_code = CODE_TRUE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
  ck_assert_double_eq_tol(result, check_result, 1e-07);
}
END_TEST

START_TEST(test_correct_str23) {
  char exprassion[100] = "(sin(12^(34-32))+6)/12.1";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  double check_result = (sin(pow(12, (34 - 32))) + 6) / 12.1;
  int check_code = CODE_TRUE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
  ck_assert_double_eq_tol(result, check_result, 1e-07);
}
END_TEST

START_TEST(test_correct_str24) {
  char exprassion[100] = "1/3";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  double check_result = 1.0 / 3.0;
  int check_code = CODE_TRUE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
  ck_assert_double_eq_tol(result, check_result, 1e-07);
}
END_TEST

START_TEST(test_correct_str25) {
  char exprassion[100] = "-123.1232";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  double check_result = -123.1232;
  int check_code = CODE_TRUE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
  ck_assert_double_eq_tol(result, check_result, 1e-07);
}
END_TEST

START_TEST(test_correct_str26) {
  char exprassion[100] = "124.4mod(12.1-0.1)";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  double check_result = fmod(124.4, (12.1 - 0.1));
  int check_code = CODE_TRUE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
  ck_assert_double_eq_tol(result, check_result, 1e-07);
}
END_TEST

Suite *correct_str() {
  Suite *result;
  TCase *tc_correct_str;

  result =
      suite_create("\033[105m  ★︎  TEST_CORRECT_STR  ★︎  \033[049m");
  tc_correct_str = tcase_create("TEST_CORRECT_STR");

  tcase_add_test(tc_correct_str, test_correct_str1);
  tcase_add_test(tc_correct_str, test_correct_str2);
  tcase_add_test(tc_correct_str, test_correct_str3);
  tcase_add_test(tc_correct_str, test_correct_str4);
  tcase_add_test(tc_correct_str, test_correct_str5);
  tcase_add_test(tc_correct_str, test_correct_str6);
  tcase_add_test(tc_correct_str, test_correct_str7);
  tcase_add_test(tc_correct_str, test_correct_str8);
  tcase_add_test(tc_correct_str, test_correct_str9);
  tcase_add_test(tc_correct_str, test_correct_str10);
  tcase_add_test(tc_correct_str, test_correct_str11);
  tcase_add_test(tc_correct_str, test_correct_str12);
  tcase_add_test(tc_correct_str, test_correct_str13);
  tcase_add_test(tc_correct_str, test_correct_str14);
  tcase_add_test(tc_correct_str, test_correct_str15);
  tcase_add_test(tc_correct_str, test_correct_str16);
  tcase_add_test(tc_correct_str, test_correct_str17);
  tcase_add_test(tc_correct_str, test_correct_str18);
  tcase_add_test(tc_correct_str, test_correct_str19);
  tcase_add_test(tc_correct_str, test_correct_str20);
  tcase_add_test(tc_correct_str, test_correct_str21);
  tcase_add_test(tc_correct_str, test_correct_str22);
  tcase_add_test(tc_correct_str, test_correct_str23);
  tcase_add_test(tc_correct_str, test_correct_str24);
  tcase_add_test(tc_correct_str, test_correct_str25);
  tcase_add_test(tc_correct_str, test_correct_str26);

  suite_add_tcase(result, tc_correct_str);

  return result;
}

/***********************************/
/********** INCORRECT_STR **********/
/***********************************/

START_TEST(test_incorrect_str1) {
  char exprassion[100] = "123.";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  int check_code = CODE_FALSE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
}
END_TEST

START_TEST(test_incorrect_str2) {
  char exprassion[100] = ".123";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  int check_code = CODE_FALSE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
}
END_TEST

START_TEST(test_incorrect_str3) {
  char exprassion[100] = "123.123+";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  int check_code = CODE_FALSE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
}
END_TEST

START_TEST(test_incorrect_str4) {
  char exprassion[100] = "/123";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  int check_code = CODE_FALSE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
}
END_TEST

START_TEST(test_incorrect_str5) {
  char exprassion[100] = "((1+2";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  int check_code = CODE_FALSE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
}
END_TEST

START_TEST(test_incorrect_str6) {
  char exprassion[100] = "((1-2)";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  int check_code = CODE_FALSE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
}
END_TEST

START_TEST(test_incorrect_str7) {
  char exprassion[100] = "sin34";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  int check_code = CODE_FALSE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
}
END_TEST

START_TEST(test_incorrect_str8) {
  char exprassion[100] = "0012";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  int check_code = CODE_FALSE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
}
END_TEST

START_TEST(test_incorrect_str9) {
  char exprassion[100] = "00.12-12";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  int check_code = CODE_FALSE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
}
END_TEST

START_TEST(test_incorrect_str10) {
  char exprassion[100] = "12-0.12.123";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  int check_code = CODE_FALSE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
}
END_TEST

START_TEST(test_incorrect_str11) {
  char exprassion[100] = "--1";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  int check_code = CODE_FALSE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
}
END_TEST

START_TEST(test_incorrect_str12) {
  char exprassion[100] = "12++123";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  int check_code = CODE_FALSE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
}
END_TEST

START_TEST(test_incorrect_str13) {
  char exprassion[100] = "atan(123-123/2))";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  int check_code = CODE_FALSE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
}
END_TEST

START_TEST(test_incorrect_str14) {
  char exprassion[100] = "123.123/0";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  int check_code = CODE_FALSE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
}
END_TEST

START_TEST(test_incorrect_str15) {
  char exprassion[100] = "asin(123)-6";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  int check_code = CODE_FALSE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
}
END_TEST

START_TEST(test_incorrect_str16) {
  char exprassion[100] = "123/acos(123)";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  int check_code = CODE_FALSE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
}
END_TEST

START_TEST(test_incorrect_str17) {
  char exprassion[100] = "123.55555-23+ln(0-123)";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  int check_code = CODE_FALSE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
}
END_TEST

START_TEST(test_incorrect_str18) {
  char exprassion[100] = "123.55555+23+log(0-123.04)";
  double result = 0;
  OBJ *stack_exprassion = NULL;

  int check_code = CODE_FALSE;

  int code = combo_calc(&stack_exprassion, exprassion, 0, &result);

  ck_assert_int_eq(code, check_code);
}
END_TEST

Suite *incorrect_str() {
  Suite *result;
  TCase *tc_incorrect_str;

  result =
      suite_create("\033[105m  ★︎ TEST_INCORRECT_STR ★︎  \033[049m");
  tc_incorrect_str = tcase_create("TEST_INCORRECT_STR");

  tcase_add_test(tc_incorrect_str, test_incorrect_str1);
  tcase_add_test(tc_incorrect_str, test_incorrect_str2);
  tcase_add_test(tc_incorrect_str, test_incorrect_str3);
  tcase_add_test(tc_incorrect_str, test_incorrect_str4);
  tcase_add_test(tc_incorrect_str, test_incorrect_str5);
  tcase_add_test(tc_incorrect_str, test_incorrect_str6);
  tcase_add_test(tc_incorrect_str, test_incorrect_str7);
  tcase_add_test(tc_incorrect_str, test_incorrect_str8);
  tcase_add_test(tc_incorrect_str, test_incorrect_str9);
  tcase_add_test(tc_incorrect_str, test_incorrect_str10);
  tcase_add_test(tc_incorrect_str, test_incorrect_str11);
  tcase_add_test(tc_incorrect_str, test_incorrect_str12);
  tcase_add_test(tc_incorrect_str, test_incorrect_str13);
  tcase_add_test(tc_incorrect_str, test_incorrect_str14);
  tcase_add_test(tc_incorrect_str, test_incorrect_str15);
  tcase_add_test(tc_incorrect_str, test_incorrect_str16);
  tcase_add_test(tc_incorrect_str, test_incorrect_str17);
  tcase_add_test(tc_incorrect_str, test_incorrect_str18);

  suite_add_tcase(result, tc_incorrect_str);

  return result;
}

int main() {
  Suite *result;
  int failed = 0;
  SRunner *runner;

  result = correct_str();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = incorrect_str();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (failed == 0) ? EXIT_SUCCESS : CK_FAILURE;
}
