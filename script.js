document.addEventListener('DOMContentLoaded', function() {
    const cars = [
        { name: 'Merceds C200d', price: 90, image: 'merceds.webp' },
        { name: 'Mahindra Thar', price: 70, image: 'Car2.webp' },
        { name: 'Huyndai Creta', price: 50, image: 'car3.webp' },
        { name: 'Huyndai Creta', price: 50, image: 'car3.webp' },
    ];

    const carList = document.getElementById('car-list');
    const carSelect = document.getElementById('car');
    const totalPriceElement = document.getElementById('total-price');

    cars.forEach(car => {
        // Add car to car list
        const carItem = document.createElement('div');
        carItem.classList.add('car-item');
        carItem.innerHTML = `
            <img src="${car.image}" alt="${car.name}">
            <h3>${car.name}</h3>
            <p>Price per day: $${car.price}</p>
        `;
        carList.appendChild(carItem);

        // Add car to car select options
        const option = document.createElement('option');
        option.value = car.name;
        option.textContent = `${car.name} ($${car.price}/day)`;
        carSelect.appendChild(option);
    });

    document.getElementById('booking-form').addEventListener('input', function() {
        const selectedCarName = carSelect.value;
        const days = document.getElementById('days').value;

        if (selectedCarName && days) {
            const selectedCar = cars.find(car => car.name === selectedCarName);
            const totalPrice = selectedCar.price * days;
            totalPriceElement.textContent = totalPrice.toFixed(2);
        } else {
            totalPriceElement.textContent = '0';
        }
    });

    document.getElementById('booking-form').addEventListener('submit', function(e) {
        e.preventDefault();
        const selectedCarName = carSelect.value;
        const days = document.getElementById('days').value;
        const selectedCar = cars.find(car => car.name === selectedCarName);
        const totalPrice = selectedCar.price * days;

        alert(`Thank you for booking a ${selectedCar.name} for ${days} days. Total price: $${totalPrice.toFixed(2)}`);
    });
});
