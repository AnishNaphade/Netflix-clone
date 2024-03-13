document.addEventListener("DOMContentLoaded", function () {
  // Assuming you have a container with id="blog-posts"
  const blogListContainer = document.getElementById("blog-posts");

  // Fetch data from JSON file
  fetch("data.json")
    .then(response => response.json())
    .then(data => {
      // Loop through each blog entry in the JSON array
      data.forEach(blogEntry => {
        // Create a card for each blog entry
        const cardElement = document.createElement("div");
        cardElement.classList.add("card", "mb-3");

        // Populate the card with data from JSON
        cardElement.innerHTML = `
          <div class="row g-0">
            <div class="col-md-4">
              <img src="${blogEntry.imagePath}" class="img-fluid rounded-start" alt="${blogEntry.title}">
            </div>
            <div class="col-md-8">
              <div class="card-body">
                <h5 class="card-title">${blogEntry.title}</h5>
                <p class="card-text">${blogEntry.content}</p>
                <p class="card-text"><small class="text-muted">${blogEntry.date}</small></p>
                <a href="${blogEntry.link}" class="btn btn-primary">Continue reading</a>
              </div>
            </div>
          </div>
        `;

        // Append the cardElement to the blogListContainer
        blogListContainer.appendChild(cardElement);
      });
    })
    .catch(error => console.error("Error fetching data:", error));
});
