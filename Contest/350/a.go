package main

func distanceTraveled(mainTank int, additionalTank int) (ans int) {
	return (mainTank + min((mainTank-1)/4, additionalTank)) * 10
}

// func distanceTraveled(mainTank int, additionalTank int) (ans int) {
// 	for mainTank >= 5 {
// 		mainTank -= 5

// 		if additionalTank > 0 {
// 			additionalTank -= 1
// 			mainTank += 1
// 		}

// 		ans += 50
// 	}
// 	return ans + mainTank*10
// }
